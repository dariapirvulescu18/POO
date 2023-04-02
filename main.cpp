#include <string>
#include <iostream>
#include <utility>
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

    leguma(std::string nume_,  int daysto_) : nume{std::move(nume_)},daysToHarvest{daysto_} {
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
    [[nodiscard]] int getdays1() const {
        return daysToHarvest;
    }
    [[nodiscard]] int getdays2() const {
        return dayspassed;
    }
};

class [[maybe_unused]] fruct {
    std::string tip;
    int kg;
public:
    friend std::ostream& operator<<(std::ostream& os, const fruct & fr) {
        os<< fr.tip<< " " << fr.kg <<"\n";
        return os;
    }

    [[maybe_unused]] fruct(std::string tip_, int kg_) : tip{std::move(tip_)}, kg{kg_} {}

};

class animal {
    std::string rasa;
    int products, dayswithoutfood, needtoeat;
    bool hungry, energy;
public:
    void become_hungry() {
        dayswithoutfood++;
        products -= 10;
        if (dayswithoutfood == needtoeat)
            hungry = true, products -= 100;
        if (hungry && dayswithoutfood >= needtoeat * 2)
            energy = false;

    }
    int gain() {
        if (!energy) {
            std::cout << "The animal is dead!" << "\n";
            return 0;
        }
        if (hungry) {
            std::cout << "The animal is hungry!" << "\n";
            return 0;
        }

        if (products > 0) {
            std::cout << "The " << rasa << " gave you " << products << "!" << "\n";
            return products;
        }
        return 0;
    }


    friend std::ostream& operator<<(std::ostream& os, const animal& anim) {
        os<< anim.rasa<< " "<< anim.products << anim.dayswithoutfood << anim.needtoeat << anim.hungry << anim.energy<<"\n";
        return os;
    }
    animal(std::string rasa_, int nte) : rasa{std::move(rasa_)},needtoeat{nte} {
        products=100*needtoeat;
        dayswithoutfood=0;
        hungry=false;
        energy=true;
    }
    const std::string & getName() {
        return rasa;
    }
    [[nodiscard]] int getproducts() const
    {
        return products;
    }
    [[nodiscard]] bool getdead() const
    {
        return energy;
    }
    [[nodiscard]] bool gethungry() const
    {
        return hungry;
    }
    [[nodiscard]] int getdays() const
    {
        return dayswithoutfood;
    }
};

class player{
    std::vector<leguma> leg;
    std::vector<animal> anim;
    int money_{}, points{};

public:
    player(const std::vector<leguma> &leg, const std::vector<animal> &anim) : leg(leg), anim(anim) {}

    void gain_money(){
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

    }
    int updateMoney(int amount) {
        money_ = amount;
        return money_;
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

    [[maybe_unused]] explicit player (const leguma& leg_, const animal & anim_) : leg{leg_}, anim{anim_} {
        money_=0;
        points=0;

    }
    [[nodiscard]] int getmoney() const
    {
        return money_;
    }

};
class unealta{
    std::string denumire;
    player &anonimus;
    int numar,object_price;
    bool want;
    int new_money{};
    bool bought;
public:
    void buy()
    { new_money=anonimus.getmoney();
        if(want and anonimus.getmoney() > object_price * numar) {
            new_money -= object_price * numar;
            std::cout<<"You have purchased "<<numar<<" "<<denumire<<" and now have "<<new_money<<" money !"<<"\n";
            bought=true;
            anonimus.updateMoney(new_money);
        }
        else {
            while(object_price*numar>anonimus.getmoney())
                    numar--;
            if(numar!=0 and want)
            {
                new_money -= object_price * numar;
                std::cout << "You have purchased " << numar << " " << denumire << " and lost " << new_money << " money !"<< "\n";
                bought=true;
                anonimus.updateMoney(new_money);
            }
            else
                std::cout<<"You can't buy this item!"<<"\n";
    }

    }
    friend std::ostream& operator<<(std::ostream& os, const unealta& une) {
        os<< une.denumire<< " " << une.numar <<"\n";
        return os;
    }

    unealta(std::string denumire_ , player &anonimus_, int numar_, int object_price_, bool want_) :
    denumire{std::move(denumire_)},anonimus{anonimus_},numar{numar_}, object_price{object_price_} ,want{want_} {

        bought=false;
    }
    [[nodiscard]] bool getBought() const
    {
        return bought;
    }
};
class  ferma {
    std::vector<unealta> crafty;
    std::vector<animal> farm_animal;
    bool ok;
    std::string nume;
public:
    void build()
    {
        for( auto &a:farm_animal) {
                ok=true;
            for (auto &u: crafty)
                if(!u.getBought())
                    ok=false;
            if(ok)
            {
                std::cout << "The animal " << a.getName() << " now has a home!" << "\n";
            }
            else
                std::cout<<"You don't have enough crafts to build this animal a home:(("<<"\n";

        }

    }

    ferma (std::vector<unealta> &crafty_,std::vector<animal> &ani, bool ok_) : crafty{crafty_},farm_animal{ani},ok{ok_} {

    }

    friend std::ostream& operator<<(std::ostream& os, const ferma& z) {
        for (const auto & c: z.crafty)
            os<<c<<" ";
        os<<"\n";
        for (const  auto & g :z.farm_animal)
            os<< g<< " ";
        os<<"\n";
        return os;
    }


};

class pamant{
    std::vector<leguma> leg;
    player & farmer;
    bool ok;
    int new_money{};

public:
    void growfaster(){
        new_money=farmer.getmoney();
        for(const auto &l:leg)
            {
            if(!l.getready() and farmer.getmoney() > 100 * l.getdays1() and ok)
                  {
                        new_money -= 100 * ( l.getdays1()-l.getdays2() );
                        std::cout<<"Now you have "<<new_money<<" money !"<<"\n";
                        farmer.updateMoney(new_money);
                    }
            else
                        std::cout<<"You can't speed up the process!"<<"\n";

            }

    }

    friend std::ostream& operator<<(std::ostream& os, const pamant& p) {
        for (const auto & l: p.leg)
            os<< l<<" ";
        os<<"\n";

        return os;
    }

    explicit pamant (std::vector<leguma>& leg_,  player &farmer_, bool ok_) : leg{leg_}, farmer{farmer_},ok{ok_}{

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
    l2.grow();
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
        vaca.become_hungry();
        gaina.become_hungry();
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
    Alex.gain_money();
    unealta lopata("shovels",Alex,5,145,true);
    unealta ciocan("hammers",Alex,4,100, true);
    unealta cuie("nails",Alex,10,50,true);
    lopata.buy();
    ciocan.buy();
    cuie.buy();
    std::vector<unealta> crafts;
    crafts.push_back(lopata);
    crafts.push_back(ciocan);
    crafts.push_back(cuie);
    ferma LOLA (crafts,farmanimal,true);
    LOLA.build();
    pamant fertil(vegetable,Alex,true);
    fertil.growfaster();

    return 0;

}