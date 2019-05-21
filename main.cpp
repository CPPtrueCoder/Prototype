#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Warrior {
public :
    virtual  unique_ptr <Warrior> clone() = 0;
    virtual void info() = 0;
    virtual ~Warrior()=default;
};

class InfantryMan:public Warrior {
    friend class PrototypeFactory;
public :
   unique_ptr <Warrior> clone() override {
        return std::make_unique<InfantryMan>(*this);
    }
    void info() override {
        cout<<"Infantryman"<<endl;

    }
private:
    InfantryMan()=default;
};
class Archer:public Warrior{
    friend class PrototypeFactory ;
public:
    unique_ptr <Warrior>  clone () override {
        return std::make_unique<Archer>(*this);
    }
    void info() override {
        cout<< " Archer"<<endl;
    }
private:
    Archer () = default;
};

class HorseMan :public Warrior{
    friend class PrototypeFactory ;
public:

        unique_ptr <Warrior> clone() override {
        return std::make_unique<HorseMan>(*this);

    }
    void info() override {
    cout<<" Horseman"<<endl;
    }
private:
    HorseMan()=default;
};

class PrototypeFactory{
public:
    unique_ptr <Warrior>  createInfMan(){
        static InfantryMan prototype;
        return prototype.clone();
    }
      unique_ptr <Warrior> createArcher(){
        static Archer prototype;
        return prototype.clone();
    }
    unique_ptr <Warrior> createHorseman(){
        static HorseMan prototype;
        return  prototype.clone();
    }
};


int main()
{
   PrototypeFactory factory;
   vector <  unique_ptr <Warrior>> v;
   v.push_back(factory.createInfMan());
   v.push_back(factory.createArcher());
   v.push_back(factory.createHorseman());
   for (auto &i:v){
       i->info();
   }

}
