#include <iostream>
#include <math.h>

using namespace std;

void swap1 (int *p,int *q) //передача параметров в функцию по ссылке(поэтому в момент передачи нам нужно разименовать указатель. * - выбирает знаечние объекта на который настроен указатель) при передачи должны указывать ссылку на переменную, из которой оператор * получит знаечние
{
    int t = *p;
    *p=*q;
    *q=t;
}

void swap2(int &r1,int &r2)//передача параметров по ссылке (при вызове передаем переменную, но в функцию передается ссылка)
{
    int t=r1;
    r1=r2;
    r2=t;
}

void swap3(int w1,int w2)
{
    int t=w1;
    w1=w2;
    w2=t;
}

template <class T> class Vector
{
    T *v;
    int sz;
    public:
        Vector(int s)
        {
            if(s<=0) cout <<"error: invalid size of vector\n";
            v = new T [sz = s];
        }
        ~Vector()
            {
                delete [] v;
            }
        T & operator[](int i)
        {
            if (i>=sz||i<0) cout<<"error: Invalid value of vector index";
            return v[i];
        }
        void operator =(const Vector &a)
            {
                if (sz!=a.sz)
                  cout<<"Недопустимый размер вектора\n"<<endl;
                for (int i = 0;i<sz ;i++) v[i]=a.v[i];
            }
        Vector(const Vector &a)
        {
            sz=a.sz;
            v = new T [sz];
            for(int i = 0;i<sz;i++)
               v[i]= a.v[i];
        }
        int size() {return sz;}
};


class vector
{
    int sz; //число элементов
    int *v; //указатель на целое
    public:
        vector(int); //конструктор
        ~vector(); //деструктор
        int & operator[](int index);
        void operator = (const vector &);
        vector(const vector &);
        int size();
        double len();


};

vector::vector(int s) //конструктор
{
    if(s<=0)
        cout<<"error: invalid size of vector\n";
    sz=s; //инициируется размер вектора
    v=new int[s]; //инициируется массив из целых
}
vector::~vector()//деструктор
{
    delete [] v;//освободить массив, на который настроен указатель на целое
}
void vector::operator =(const vector &a)//оператор присвоения одноговектора дургому
{
    if(sz!=a.sz)
       cout<<"Недопустимый размер вектора\n";
    for (int i = 0;i<sz;i++) v[i] = a.v[i];
}
vector::vector(const vector &a)//инициация присвоением
{
    sz=a.sz;
    v = new int[sz];
    for(int i = 0;i<sz;i++)
       v[i]= a.v[i];

}
int & vector::operator[](int index)//обращение к элементу
{
    if (index>=sz||index<0) cout<<"error: Invalid value of vector index";
    return v[index];
}
int vector::size(){return sz;}//возврат размера вектора
double vector::len()//возврат длины вектора
{
    int SUM = 0;
//    cout<<"&a=vector = "<<&a<<endl;
    for(int i = 0;i<sz;i++)
    {
        SUM = SUM +v[i]*v[i];
    }

//    cout<<"SUM = " << SUM<<endl;
    return sqrt(SUM);
}


int main()
{

    vector v1(2);

    v1[0]=3;
    v1[1]=4;

    vector v2(2);
    v2=v1;

    cout<<"v1[0] = "<<v1[0]<<"\n";
    cout<<"v1[1] = "<<v1[1]<<"\n";

    cout<<"v2[0] = "<<v2[0]<<"\n";
    cout<<"v2[1] = "<<v2[1]<<"\n";

    cout<<"size of v1 = "<<v1.size()<<endl;
    cout<<"size of v2 = "<<v2.size()<<endl;

    cout<<"len of v1 = "<<v1.len()<<"\n";

    Vector <double> vd1(2);
    vd1[0] = 1.5;
    vd1[1] = 1.7;

    Vector <double> vd2(2);
    vd2=vd1;

    cout<<"vd1[0] = "<<vd1[0]<<"\n";
    cout<<"vd1[1] = "<<vd1[1]<<"\n";

    cout<<"vd2[0] = "<<vd2[0]<<"\n";
    cout<<"vd2[1] = "<<vd2[1]<<"\n";

    cout<<"size of vd1 = "<<vd1.size()<<endl;
    cout<<"size of vd2 = "<<vd2.size()<<endl;

    Vector <char> vc1(2);
    vc1[0] = 'q';
    vc1[1] = 'w';

    Vector <char> vc2(2);
    vc2=vc1;

    cout<<"vc1[0] = "<<vc1[0]<<"\n";
    cout<<"vc1[1] = "<<vc1[1]<<"\n";

    cout<<"vc2[0] = "<<vc2[0]<<"\n";
    cout<<"vc2[1] = "<<vc2[1]<<"\n";

    cout<<"size of vc1 = "<<vc1.size()<<endl;
    cout<<"size of vc2 = "<<vc2.size()<<endl;

    return 0;
}

//    int a,b;

//    a=1;
//    b=2;

//    cout<<"\n swap1(&a,&b) :\n";
//    cout<<"a="<<a<<"\n";
//    cout<<"b="<<b<<"\n";
//    cout<<"&a="<<&a<<"\n";
//    cout<<"&b="<<&b<<"\n";
//    swap1(&a,&b);
//    cout<<"a="<<a<<"\n";
//    cout<<"b="<<b<<"\n";
//    cout<<"&a="<<&a<<"\n";
//    cout<<"&b="<<&b<<"\n";
//    /*out<<"*a="<<*a<<"\n";
//    cout<<"*b="<<*b<<"\n";*/


//    cout<<"\n swap2(a,b) :\n";
//    cout<<"a="<<a<<"\n";
//    cout<<"b="<<b<<"\n";
//    cout<<"&a="<<&a<<"\n";
//    cout<<"&b="<<&b<<"\n";
//    swap2(a,b);
//    cout<<"a="<<a<<"\n";
//    cout<<"b="<<b<<"\n";
//    cout<<"&a="<<&a<<"\n";
//    cout<<"&b="<<&b<<"\n\n";

//    cout<<"\nswap3(a,b) :\n";
//    cout<<"a="<<a<<"\n";
//    cout<<"b="<<b<<"\n";
//    cout<<"&a="<<&a<<"\n";
//    cout<<"&b="<<&b<<"\n";
//    swap3(a,b);
//    cout<<"a="<<a<<"\n";
//    cout<<"b="<<b<<"\n";
//    cout<<"&a="<<&a<<"\n";
//    cout<<"&b="<<&b<<"\n\n";

 \
//    cout << "Hello World!" << endl;
//    return 0;
//}
