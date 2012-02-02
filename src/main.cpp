#include "dump.h"

int main()
{
    Dump *dump = Dump::Create();
    int ret = dump->Run();
    Dump::Destroy();
    return ret;
}
