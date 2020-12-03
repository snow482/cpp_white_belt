#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;


class FunctionPart{
private:
    double Apply(double source_value) const {
        if(operation == '+'){
            return source_value + value;
        }else{
            return source_value - value;
        }
    }

private:
    char operation;
    double value;
};


class Function{
public:

    void AddPart(char operation, double value){
        parts.push_back({operation, value});
    }
    double Apply(double value) const {
        for(const FunctionPart& part : parts){
            value = part.Apply(value);
        }
        return value;
    }


private:
    vector<FunctionPart> parts;


};



struct Image{
    double quality;
    double freshness;
    double rating;
};

struct Params{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
};

Function MakeWeightFunction(const Image& image, const Params& params){
    Function function = MakeWeightFunction(image, params);
    return function.Apply(image.quality);
}

double ComputeImageWeight(const Image& image, const Params& params){
    double weight = image.quality;
    weight -= image.freshness * params.a + params.b;
    weight += image.rating * params.c;
    return weight;
}

double ComputeImageQuality(const Image& image, const Params& params, double weight){
    double quality = weight;
    quality -= image.rating * params.c;
    quality += image.freshness * params.a + params.b;
    return quality;
}


int main(){









    return 0;
}


