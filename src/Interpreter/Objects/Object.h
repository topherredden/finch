#pragma once

#include <iostream>
#include <vector>

#include "Macros.h"
#include "Ref.h"
#include "String.h"

namespace Finch
{
    using std::vector;
    
    class Expr;
    class Scope;
    class BlockObject;
    class DynamicObject;
    class Environment;
    
    class Object
    {
    public:
        // virtual constructors
        static Ref<Object> NewObject(Ref<Object> prototype, String name);
        static Ref<Object> NewObject(Ref<Object> prototype);
        static Ref<Object> NewNumber(Ref<Object> prototype, double value);
        static Ref<Object> NewString(Ref<Object> prototype, String value);
        static Ref<Object> NewBlock(Ref<Object> prototype, Ref<Expr> value);
        
        virtual ~Object() {}
        
        //### bob: pass args by const&
        virtual Ref<Object> Receive(Ref<Object> thisRef, Environment & env,
                                    String message, const vector<Ref<Object> > & args);
        
        virtual double          AsNumber() const { return 0; }
        virtual String          AsString() const { return ""; }
        virtual BlockObject *   AsBlock()        { return NULL; }
        virtual DynamicObject * AsDynamic()      { return NULL; }
        
        virtual void Trace(std::ostream & stream) const = 0;
        
    protected:
        Object() : mPrototype(Ref<Object>()) {}
        Object(Ref<Object> prototype) : mPrototype(prototype) {}
        
        Ref<Object> Prototype() const { return mPrototype; }
        
    private:
        Ref<Object> mPrototype;
    };
    
    std::ostream& operator<<(std::ostream& cout, const Object & object);
}