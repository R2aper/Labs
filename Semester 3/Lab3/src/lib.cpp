#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "../include/lib.hpp"

using namespace std;

PopulationGrowth::PopulationGrowth(){
    name = "";
    growth2010 = 0;
    growth2011 = 0;
    growth2012 = 0;
    growth2013 = 0;
    growth2014 = 0;
}

PopulationGrowth::PopulationGrowth(string name, int growth2010, int growth2011, int growth2012, int growth2013, int growth2014){
        this->name = name;
        this->growth2010 = growth2010;
        this->growth2011 = growth2011;
        this->growth2012 = growth2012;
        this->growth2013 = growth2013;
        this->growth2014 = growth2014;
}

void PopulationGrowth::Print() {
    cout << name << setw(5) << "\t" << growth2010  << setw(5) << growth2011 << setw(5) 
    << growth2012 << setw(5) << growth2013 
    << setw(5) << growth2014 << endl;
}

void PopulationGrowth::setName(string name) { this->name = name; }
void PopulationGrowth::setGrowth2010(int growth2010) { this->growth2010 = growth2010; }
void PopulationGrowth::setGrowth2011(int growth2011) { this->growth2011 = growth2011; }
void PopulationGrowth::setGrowth2012(int growth2012) { this->growth2012 = growth2012; }
void PopulationGrowth::setGrowth2013(int growth2013) { this->growth2013 = growth2013; }
void PopulationGrowth::setGrowth2014(int growth2014) { this->growth2014 = growth2014; }


string PopulationGrowth::GetName() {return name; }
int PopulationGrowth::GetGrowth2010() { return growth2010; }
int PopulationGrowth::GetGrowth2011() { return growth2011; }
int PopulationGrowth::GetGrowth2012() { return growth2012; }
int PopulationGrowth::GetGrowth2013() { return growth2013; }
int PopulationGrowth::GetGrowth2014() { return growth2014; }