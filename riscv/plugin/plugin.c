#include "riscv/mmio_plugin.h"
#include <stdio.h>
#include <string.h>

static unsigned int ret = 0x66778899;

void* test_mmio_plugin_alloc(const char* args)
{
    printf("ALLOC -- ARGS=%s\n", args);
    return (void*)0x0123456789abcdef;
}

bool test_mmio_plugin_load(void* self, reg_t addr, size_t len, uint8_t* bytes)
{
    printf("LOAD -- SELF=%p ADDR=0x%lx LEN=%lu BYTES=%x\n", self, addr, len, *bytes);
    memcpy(bytes, &ret, 4);

    // *bytes=0x44;*(bytes+1)=0x55;*(bytes+2)=0x66;*(bytes+3)=0x77;
    // printf("LOAD -- SELF=%p ADDR=0x%lx LEN=%lu BYTES=%p\n", self, addr, len, bytes);
    return true;
}

bool test_mmio_plugin_store(void* self, reg_t addr, size_t len, const uint8_t* bytes)
{
    char *funct1="";
    char *funct2="";
    uint32_t addr1=0X0;
    uint32_t addr2=0X0;
    // bool store(reg_t addr, size_t len, const uint8_t* bytes) {
        // if (len != 4) return false;  // only 4 byte stores supported
        // memcpy(&ret, bytes, 4);
        // printf("ret=%x\n", ret);
    //     return true;
    // }
    if(addr==0x4){
        // FUNC
        switch (*bytes)
        {
        case 0x0:
            funct1="LOAD";
            break;
        case 0x1:
            funct1="STORE";
            break;
        case 0x2:
            funct1="COMP";
            break;
        default:
            break;
        }
    }
    printf("ADDR=0x%lx LEN=%lu BYTES=%x, cmd=%s\n", addr, len, *(bytes), funct1);
    // uint8_t *addr_mod=addr+0x4;
    // *addr_mod=55;
    // uint8_t *addr_mod=bytes+0x4;
    // *addr_mod=55;
    // printf("after mod, at addr%p=%x\n",addr_mod,*(addr_mod));
    // test_mmio_plugin_load(self, addr+4, len, (uint8_t*)(bytes));
    return true;
}

void test_mmio_plugin_dealloc(void* self)
{
    printf("DEALLOC -- SELF=%p\n", self);
}

__attribute__((constructor)) static void on_load()
{
  static mmio_plugin_t test_mmio_plugin = {
      test_mmio_plugin_alloc,
      test_mmio_plugin_load,
      test_mmio_plugin_store,
      test_mmio_plugin_dealloc,
};

  register_mmio_plugin("test_mmio_plugin", &test_mmio_plugin);
}
