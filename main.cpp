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
        cantitate=daysToHarvest*10;
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
};

class fruct {
    std::string tip;
    int kg;
public:
    friend std::ostream& operator<<(std::ostream& os, const fruct & fr) {
        os<< fr.tip<< " " << fr.kg <<"\n";
        return os;
    }
    fruct(const std::string &tip_, int kg_) : tip{tip_}, kg{kg_} {}

};
class animal {
    std::string rasa;
    int nr;
public:
    friend std::ostream& operator<<(std::ostream& os, const animal& anim) {
        os<< anim.rasa<< " " << anim.nr <<"\n";
        return os;
    }
    animal(const std::string &rasa_, int nr_) : rasa{rasa_}, nr{nr_} { }

};
class unealta{
    std::string denumire;
    int numar;
public:
    friend std::ostream& operator<<(std::ostream& os, const unealta& une) {
        os<< une.denumire<< " " << une.numar <<"\n";
        return os;
    }
    unealta(const std::string &denumire_, int numar_) : denumire{denumire_}, numar{numar_}  { }

};
class ferma {
    std::string custi_animale;
    unealta unelt;
public:
    friend std::ostream& operator<<(std::ostream& os, const ferma& fe) {
        os<< fe.custi_animale<< " " << fe.unelt<<"\n";
        return os;
    }
    ferma(const std::string &custi, unealta u) : custi_animale{custi}, unelt{std::move(u)} {}
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
int main()
{
        leguma cartof("cartof", 3);
        leguma rosie("rosie",5);

        std::cout << "You have planted " << cartof.getName() << " and " << rosie.getName() << "." <<"\n";
    for (int i = 0; i <3; i++) {
        cartof.grow();
        rosie.grow();
    }

    cartof.harvested();
    rosie.harvested();

        return 0;

}