#include <iostream>
#include <list>




using namespace std;



int main(){

list <int >numeros;


numeros.push_back(5);

numeros.push_back(20);

numeros.push_back(12);

numeros.push_back(7);





for (auto num = numeros.begin(), e = numeros.end(); num != e; ++num)
//  iteramos tantas veces como elementos existan entre begin y end
    {
        cout<<*num<<endl;
    }


return 0;
}
