#include <iostream>

#include "LexerTests.h"
#include "QueueTests.h"
#include "RefTests.h"
#include "StackTests.h"
#include "StringTests.h"
#include "TestMain.h"
#include "TokenTests.h"

namespace Finch
{
    void TestMain::Run()
    {
        std::cout << "Running unit tests:" << std::endl;
        
        LexerTests::Run();
        QueueTests::Run();
        RefTests::Run();
        StackTests::Run();
        StringTests::Run();
        TokenTests::Run();

        Test::ShowResults();
    }
}