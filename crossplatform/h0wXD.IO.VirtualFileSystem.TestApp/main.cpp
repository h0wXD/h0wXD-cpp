#include <iostream>
#include <memory>
#include "..\h0wXD.IO.VirtualFileSystem\DummyMethods.h"

int main()
{
    std::unique_ptr<DummyMethods> pDummyMethods(new DummyMethods());
    std::cout << pDummyMethods->HelloWorld() << std::endl;
    return 0;
}
