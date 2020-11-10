#include <iostream>
#include <string>
#include <fstream>
#include <memory>

class Test {
public:
    Test() = default;
    explicit Test(int x, int y=7) // аргументы по умолчанию
    // можно либо (int x, int y = 7), либо (int x = 5, int y = 7)
    // (int x = 5, int y) - НЕЛЬЗЯ
            : m_x(x), m_y(y) // initialization of properties
    {
        std::cout << "Constructor"<<std::endl;
    }
    explicit Test(std::string s)
            : m_s(s)
    {
        std::cout << "Constructor2"<<std::endl;
        m_x = 0;
        m_y = 0;
    }
    ~Test()noexcept{
        std::cout << "Destructor"<<std::endl;
    }

private:
    int m_x =0, m_y=0;
    std::string m_s;
};

void func(Test t){}

//RAII
class Memory{
public:
    Memory(int n){
        std::cout << "ConstrMem"<<std::endl;
        arr = new int[n];
    }
    ~Memory(){
        delete[] arr;
        std::cout << "DestMem"<<std::endl;
    }

    int Value(int x) const {
        return arr[x];
    }

private:
    int* arr = nullptr;
};

class Input{
public:
    Input(int x){}
    void DoThmth(){}
};

class Wrap{
public:
    Wrap(){
        m_i = std::make_unique<Input>(10);
        m_i2 = std::make_shared<Input>(10);

        m_i2->DoThmth();//
        //m_i2. //

        std::shared_ptr<Input> ii = m_i2;
        std::weak_ptr<Input> wp = ii;

        std::shared_ptr<Input> sp = wp.lock();
        //sp == nullptr ? object
    }
private:
    std::unique_ptr<Input> m_i = nullptr;
    std::shared_ptr<Input> m_i2 = nullptr;
};

int main() {
    Wrap w;
    {
        /* int x = 10;
         func(x); // explicit запрещает подобные действия*/
        std::ofstream out{"output.txt"};
        out << "Hello my file";
        //Test a{"asd"};
        //Memory m(100);

        //m.Value(4) = 9;
    }
    //Test b{4,7};

    {   // хороший способ конструирования
        // std::unique_ptr<Test> t = std::make_unique<Test>(10,17);
        std::unique_ptr<Test> t = nullptr;
        t = std::make_unique<Test>(10,17);

    }

    return 0;
}

