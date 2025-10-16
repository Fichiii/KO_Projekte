#include "Instance.hpp"

int Instance::getNumberOfItems() const{
    return values.size();
}

int Instance::n() {
    return getNumberOfItems();
}

Instance::Instance(int number)
        : values(vector<int>(number, 0))
        , weights(vector<int>(number, 0))
        , weightLimit(0)
        , filename() {}

void Instance::setValue(int item, int value) { 
    values.at(item) = value; 
}

int Instance::getValue(int item) const {
    return values.at(item); 
}

void Instance::setWeight(int item, int weight) {
     weights.at(item) = weight; 
}

int Instance::getWeight(int item) const {
     return weights.at(item); 
}

void Instance::setFilename(string name) {
     filename = name;
}

string Instance::getFilename() const {
     return filename; 
}

int Instance::getCapacity() const {
     return weightLimit; 
}
void Instance::setCapacity(int capacity) {
     weightLimit = capacity; 
}

void Instance::set(int item, int value, int weight) {
    Instance::setValue(item, value);
    Instance::setWeight(item, weight);
}

