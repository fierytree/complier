#include "type.h"
extern ofstream fout;
Type::Type(ValueType valueType) {
    this->type = valueType;
}

void Type::addChild(Type* t){
    childType.push_back(t);
}

bool Type::operator==(Type t){
    //fout<<"1111 "<<type<<" "<<t.type<<endl;
    if((this->type==COMPOSE_ARRAY&&t.type==COMPOSE_POINTER)||
    (t.type==COMPOSE_ARRAY&&this->type==COMPOSE_POINTER)){
        Type*t1;Type*t2;
        if(this->type==COMPOSE_ARRAY)t2=this,t1=&t;
        else t1=this,t2=&t;
        t1=t1->retType;
        while(t2->type==COMPOSE_ARRAY)t2=t2->retType;
        return *t1==*t2;
    }
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
    else if(type==COMPOSE_POINTER)return *retType==*t.retType;
    else if(type==COMPOSE_STRUCT)return name==t.name;
    else return 1;
}
bool Type::operator!=(Type t){return !((*this)==t);}
void Type::addret(Type* t){
    Type* tmp=this;
    while(tmp->retType!=nullptr)tmp=tmp->retType;
    tmp->retType=t;
}
int Type::sz(){
    if(type==VALUE_BOOL)return 1;
    else if(type==VALUE_CHAR)return 1;
    else if(type==VALUE_STRING)return size;
    else if(type==VALUE_VOID)return 0;
    else if(type==COMPOSE_ARRAY){
        int cnt=1;
        Type* t=this;
        while(t->type==COMPOSE_ARRAY)cnt*=t->size,t=t->retType;
        return cnt*(t->sz());
    }
    else if(type==COMPOSE_STRUCT){
        int cnt=0;
        for(auto x:paramType->childType)cnt+=x->sz();
        return cnt;
    }
    return 4; 
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
        case COMPOSE_POINTER:
            return "pointer";
        case COMPOSE_STRUCT:
            return "struct";
        default:
            cerr << "shouldn't reach here, typeinfo";
            assert(0);
    }
    return "?";
}