#pragma once

#include <vector>

#include "Expr.h"
#include "Macros.h"
#include "Object.h"
#include "Ref.h"
#include "String.h"

namespace Finch
{
    using std::vector;
    
    // Primitive methods for the global Ether object.
    PRIMITIVE(EtherQuit);
    
    // Flow control
    PRIMITIVE(EtherDo);
    PRIMITIVE(EtherIfThen);
    PRIMITIVE(EtherIfThenElse);
    PRIMITIVE(EtherWhileDo);
    
    // Basic IO
    PRIMITIVE(EtherWrite);
    PRIMITIVE(EtherWriteLine);
    PRIMITIVE(EtherLoad);
}