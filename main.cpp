#include <string>
#include <iostream>
#include <vector>

class leguma{
private:
    std::string nume;
    int cantitate,daysToHarvest,dayspassed;
    bool isReadyToHarvest;

public:

    void grow() {
        dayspassed++;
        cantitate+=dayspassed*daysToHarvest;
        if (daysToHarvest == dayspassed)
            isReadyToHarvest = true;

    }

    int harvested() {
        if (isReadyToHarvest) {
            std::cout << "You have harvested " << cantitate << " kg de "<<  nume << "!" << "\n";
            return cantitate;
        }
        else {
            std::cout << "This crop is not ready to harvest yet." <<"\n";
            cantitate=0;
            return 0;
        }
    }


    leguma& operator = (const leguma& other) {
        nume = other.nume;
        cantitate = other.cantitate;
        daysToHarvest=other.daysToHarvest;
        dayspassed=other.dayspassed;
        isReadyToHarvest=other.isReadyToHarvest;


        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const leguma& le){
        os<< le.nume<< " " << le.cantitate <<" "<<le.dayspassed<<" "<<le.isReadyToHarvest<<" "<< le.daysToHarvest<<"\n";
        return os;
    }

    leguma(const std::string &nume_,  int daysto_) : nume{nume_},daysToHarvest{daysto_} {
        cantitate=0;
        dayspassed=0;
        isReadyToHarvest= false;
    }

    leguma(const leguma &other) : nume{other.nume}, cantitate{other.cantitate},
                                  daysToHarvest{other.daysToHarvest},dayspassed{other.dayspassed}, isReadyToHarvest{other.isReadyToHarvest}{}
    ~leguma() {
        std::cout<<"am distrus"<<"\n";
    }
    const std::string & getName() {
        return nume;
    }
    [[nodiscard]] int getquantity() const {
        return cantitate ;
    }
    [[nodiscard]] bool getready() const{
        return isReadyToHarvest;
    }
};

class fruct {
    std::string tip;
    int kg;
public:
    friend std::ostream& operator<<(std::ostream& os, const fruct & fr) {
        os<< fr.tip<< " " << fr.kg <<"\n";
        return os;
    }
    fruct(std::string tip_, int kg_) : tip{std::move(tip_)}, kg{kg_} {}

};

class animal {
    std::string rasa;
    int products,dayswithoutfood,needtoeat;
    bool hungry,energy;
public:
    void hungryy()
    { dayswithoutfood++;
        products-=10;
        if(dayswithoutfood==needtoeat)
            hungry= true, products-=100;
        if(hungry && dayswithoutfood >= needtoeat * 2)
            energy=false;

    }

    int gain()
    {    if (!energy) {
            std::cout << "The animal is dead!" << "\n";
            return 0;
        }
        if(hungry)
        {   std::cout << "The animal is hungry!" << "\n";
            return 0;
        }

        if(products>0){
            std::cout <<"The " << rasa << " gave you " << products <<"!"<<"\n";
            return products;
        }
    }



    friend std::ostream& operator<<(std::ostream& os, const animal& anim) {
        os<< anim.rasa<< " "<< anim.products << anim.dayswithoutfood << anim.needtoeat << anim.hungry << anim.energy<<"\n";
        return os;
    }
    animal(const std::string &rasa_, int nte) : rasa{rasa_},needtoeat{nte} {
        products=100*needtoeat;
        dayswithoutfood=0;
        hungry=false;
        energy=true;
    }
    const std::string & getName() {
        return rasa;
    }
    int getproducts()
    {
        return products;
    }
    bool getdead()
    {
        return energy;
    }
    bool gethungry()
    {
        return hungry;
    }
    int getdays()
    {
        return dayswithoutfood;
    }
};



class unealta{
    std::string denumire;
    int numar;
public:
    friend std::ostream& operator<<(std::ostream& os, const unealta& une) {
        os<< une.denumire<< " " << une.numar <<"\n";
        return os;
    }
    unealta(std::string denumire_, int numar_) : denumire{std::move(denumire_)}, numar{numar_}  { }

};
class ferma {
    std::string custi_animale;
    unealta unelt;
public:
    friend std::ostream& operator<<(std::ostream& os, const ferma& fe) {
        os<< fe.custi_animale<< " " << fe.unelt<<"\n";
        return os;
    }
    ferma(std::string custi, unealta u) : custi_animale{std::move(custi)}, unelt{std::move(u)} {}
};

class pamant{
    std::vector<leguma> leg;
    std::vector<fruct> fru;

public:
    friend std::ostream& operator<<(std::ostream& os, const pamant& p) {
        for (const auto & l: p.leg)
            os<< l<<" ";
        os<<"\n";
        for (const  auto & f :p.fru)
            os<< f<< " ";
        os<<"\n";
        return os;
    }
    explicit pamant (const leguma& leg_, const fruct & fru_) : leg{leg_}, fru{fru_} {}


};
class player{
    std::vector<leguma> leg;
    std::vector<animal> anim;
    int money_{}, points{};
public:
    player(const std::vector<leguma> &leg, const std::vector<animal> &anim) : leg(leg), anim(anim) {}

    int money(){
        for(auto &l:leg)
        { money_+=10*l.getquantity();
            points+=l.getquantity();
            if(!l.getready()) {
                money_ -= 10;
                points -= 1;
            }
        }
        for(auto &a:anim)
        { money_+=100*a.getproducts();
            points+=10*a.getproducts();
            if(!a.getdead())
            { money_-=100;
                points-=100;
            }
            if(a.gethungry())
            { money_-=10*a.getdays();
                points-=a.getdays();
            }
        }
        std::cout<<"You have gained "<<money_<<" money and "<<points<<" points"<<"\n";
        return money_;
        return points;
    }

    friend std::ostream& operator<<(std::ostream& os, const player& p) {
        for (const auto & l: p.leg)
            os<< l<<" ";
        os<<"\n";
        for (const  auto & f :p.anim)
            os<< f<< " ";
        os<<"\n";
        return os;
    }
    explicit player (const leguma& leg_, const animal & anim_) : leg{leg_}, anim{anim_} {
        money_=0;
        points=0;

    }



};
int main()
{
    leguma cartof("potato", 3);
    leguma rosie("tomato",5);
    animal vaca("cow",6);
    animal gaina("chiken",3);
    leguma l1("l1",5),l2(l1),l3("l3",6);
    l3=l2;
    std::cout<<l1<<" "<<l2<<" "<<l3<<"\n";

    std::cout << "You have planted " << cartof.getName() << " and " << rosie.getName() << "." <<"\n";
    for (int i = 0; i <3; i++) {
        cartof.grow();
        rosie.grow();
    }

    cartof.harvested();
    rosie.harvested();

    std::cout<<"You have in your farm a "<< vaca.getName()<< " and a " << gaina.getName() << "."<<"\n";
    for (int i =0;i<19;i++)
    {
        vaca.hungryy();
        gaina.hungryy();
    }
    vaca.gain();
    gaina.gain();

    std::vector<leguma>vegetable;
    std::vector<animal>farmanimal;

    vegetable.push_back(cartof);
    vegetable.push_back(rosie);

    farmanimal.push_back(vaca);
    farmanimal.push_back(gaina);

    player Alex(vegetable,farmanimal);
    Alex.money();

    return 0;

}