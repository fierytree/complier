#ifndef TYPESYSTEM_H
#define TYPESYSTEM_H
#include "./pch.h"
using namespace std;

enum ValueType
{
    VALUE_BOOL,
    VALUE_INT,
    VALUE_CHAR,
    VALUE_STRING,
    VALUE_VOID,
    COMPOSE_STRUCT,
    COMPOSE_UNION,
    COMPOSE_FUNCTION,
    COMPOSE_ARRAY,
    COMPOSE_POINTER
};

class Type
{
public:
    ValueType type;
    Type(ValueType valueType);
public:  
    /* 如果你要设计复杂类型系统的话，可以修改这一部分 */
    vector<Type*> childType; // for union or struct
    Type* paramType;
    Type* retType; // for function or array
    unsigned size; // for array
    string name;
    
    void addChild(Type* t);
    void addret(Type* t);
    int sz();
 
public:
    string getTypeInfo();
    bool operator==(Type t);
    bool operator!=(Type t);
};

// 设置几个常量Type，可以节省空间开销
static Type* TYPE_INT = new Type(VALUE_INT);
static Type* TYPE_CHAR = new Type(VALUE_CHAR);
static Type* TYPE_BOOL = new Type(VALUE_BOOL);
static Type* TYPE_STRING = new Type(VALUE_STRING);
static Type* TYPE_VOID = new Type(VALUE_VOID);

int getSize(Type* type);

#endif