#include "type.h"

Type::Type(ValueType valueType) {
    this->type = valueType;
}

void Type::addChild(Type* t){
    childType.push_back(t);
}

bool Type::operator==(Type t){
    //cout<<"1111 "<<type<<" "<<t.type<<endl;
    if(this->type!=t.type)return 0;
    if(type==COMPOSE_ARRAY){
        if(size!=t.size)return 0;
        return *retType==*t.retType;
    }
    else if(type==COMPOSE_FUNCTION){
        if(*paramType!=*t.paramType)return 0;
        if(*retType!=*t.retType)return 0;
        return 1;
    }
    else if(type==COMPOSE_UNION){
        if(childType.size()!=t.childType.size())return 0;
        for(unsigned i=0;i<childType.size();i++){
            if(*childType[i]!=*t.childType[i])return 0;
        }
        return 1;
    }
    else return 1;
}
bool Type::operator!=(Type t){return !((*this)==t);}
void Type::addret(Type* t){
    Type* tmp=this;
    while(tmp->retType!=nullptr)tmp=tmp->retType;
    tmp->retType=t;
}
string Type::getTypeInfo() {
    switch(this->type) {
        case VALUE_BOOL:
            return "bool";
        case VALUE_INT:
            return "int ";
        case VALUE_CHAR:
            return "char";
        case VALUE_STRING:
            return "string";
        case VALUE_VOID:
            return "void";
        case COMPOSE_ARRAY:
            return "array";
        case COMPOSE_FUNCTION:
            return "function";
        case COMPOSE_UNION:
            return "union";
        default:
            cerr << "shouldn't reach here, typeinfo";
            assert(0);
    }
    return "?";
}