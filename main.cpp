//
// Created by arina on 28.05.2021.
//

#include <iostream>
#include <algorithm>
#include <string>
#include "menuTree.h"
#include <random>
#include <ctime>
#include <complex>
//#include "search_tree.h
#include "BinaryTree.h"
using namespace std;




int main() {
    BinaryTree<int> t;
    t.Insert(15);
    t.Insert(20);
    t.Insert(25);
    t.Insert(10);
//    t.GetStrGreatTree();
    t.Insert(30);
    t.Insert(11);
    t.Insert(31);
    t.Insert(3);
    t.Insert(34);
    t.Insert(35);
    t.Insert(38);

    t.Insert(234);
    t.Insert(23);
//    t.GetStrGreatTree();
//    BinaryTree<int> *a;
//    t.Remove(20);
//    t.GetStrGreatTree();
//    t.Remove(25);
//    t.GetStrGreatTree();
//    t.Remove(30);

    cout << t.GetStrGreatTree();
    mainMenuBinaryTree();
    return 0;
}








/*
template<typename T>
T set_nul()
{
    return (T)0;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    srand((time(0)));
    int f[16]={6,5,7,98,38,4,875,10,10,70,1,2,3,1,2,3};

    int work=-1;
    int question=-1;
    int function=0;
    Search_tree<int> a(f, 10);
    a.klp_t();
    cout<<"\n";
    a.add_el(-10); //вставка
    cout<<"\n";
    Search_tree<int> b(a.klp_t());
    cout<<"\n";
    b.klp_t();
    cout<<"\n";
    cout<<b.find_el(-15)<<endl<<b.get_length()<<endl;
    cout<<"\n";
    Search_tree<int>* c=b.get_subtree(38);
    c->klp_t();
    cout<<"\n";
    cout<<b.find_subtree(*c);
    cout<<"\n";
    Search_tree<int>* d=new Search_tree<int>(b);
    d->klp_t();
    while(question!=0)
    {
        cout<<"\nДля завершения программы нажмите 0\nДля работы с десятичными числами введите 1\n";
        cin>>question;

        if(question==0)
            continue;
            /*else if(question==1)
            {

                Queue<string> firsts;
                string temps;
                int start_index,end_index;
                if(firsts.nun())
                {
                    cout<<"Заполните очередь\nВведите длину: ";
                    int len;
                    cin>>len;
                    cout<<"Введите последоваельность\n";
                    for(int i=0;i<len;i++)
                    {
                        cin>>temps;
                        firsts.add_el(temps);
                    }
                }
                while(work!=0)
                {
                    cout<<"для добавления элемента введите 1\nДля извлечения максимального элемента введите 2\nДля извлечения минимального элемента введите 3\nДля извлечения подпоследовательности введите 4\nДля поиска подпоследовательности введите 5\nMap-6\nWhere-7\nReduce-8\nConcat-9\n";
                    cin>>function;
                    switch (function)
                    {

                    case 1:
                        cout<<"Введите строку: ";
                        cin>>temps;
                        firsts.add_el(temps);
                        firsts.print();
                        break;
                    case 2:
                        cout<<firsts.get_max()<<endl;
                        break;
                    case 3:
                        cout<<firsts.get_min()<<endl;
                        break;
                    case 4:
                    {
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }
                        firsts.print();
                        cout<<"Введите начало: ";
                        cin>>start_index;
                        cout<<"Введите конец: ";
                        cin>>end_index;

                        Queue<string>* seconds=firsts.get_subsequence(start_index,end_index);
                        seconds->print();
                    }
                        break;
                    case 5:
                    {
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }
                        int size=0;
                        cout<<"Введите размер подпоследовательности: ";
                        cin>>size;
                        string temp[size];
                        cout<<"Введите подпоследовательность\n";
                        for(int i=0;i<size;i++)
                        {
                            cin>>temp[i];
                        }
                        cout<<firsts.find_subsequence(temp,size);
                    }
                        break;
                    case 6:
                    {
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }
                        firsts.map(set_nul);
                        firsts.print();
                    }
                        break;
                    case 7:
                    {
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }

                    }

                        break;
                    case 8:
                    {
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }

                    }

                        break;
                    case 9:
                    {
                        Queue<string> second;
                        Queue<string> *third;
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }
                        int size=0;
                        cout<<"Введите размер последовательности: ";
                        cin>>size;
                        cout<<"Введите последовательность\n";
                        for(int i=0;i<size;i++)
                        {
                            cin>>temps;
                            second.add_el(temps);
                        }
                        second.print();
                        third=firsts.concat(second);
                        third->print();
                    }

                        break;
                    default:
                        break;
                    }
                    cout<<"Для продолжения введите 1, иначе 0: ";
                    cin>>work;



                }
            }


        else if(question==1)
        {

            Queue<double> firsts;
            double temps;
            int start_index,end_index;
            if(firsts.nun())
            {
                cout<<"Заполните очередь\nВведите длину: ";
                int len;
                cin>>len;
                cout<<"Введите последоваельность\n";
                for(int i=0;i<len;i++)
                {
                    cin>>temps;
                    firsts.add_el(temps);
                }
            }
            while(work!=0)
            {
                cout<<"для добавления элемента введите 1\nДля извлечения максимального элемента введите 2\nДля извлечения минимального элемента введите 3\nДля извлечения подпоследовательности введите 4\nДля поиска подпоследовательности введите 5\nMap-6\nWhere-7\nReduce-8\nConcat-9\n";
                cin>>function;
                switch (function)
                {

                    case 1:
                        cout<<"Введите строку: ";
                        cin>>temps;
                        firsts.add_el(temps);
                        firsts.print();
                        break;
                    case 2:
                        cout<<firsts.get_max()<<endl;
                        break;
                    case 3:
                        cout<<firsts.get_min()<<endl;
                        break;
                    case 4:
                    {
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }
                        firsts.print();
                        cout<<"Введите начало: ";
                        cin>>start_index;
                        cout<<"Введите конец: ";
                        cin>>end_index;

                        Queue<double>* seconds=firsts.get_subsequence(start_index,end_index);
                        seconds->print();
                    }
                        break;
                    case 5:
                    {
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }
                        int size=0;
                        cout<<"Введите размер подпоследовательности: ";
                        cin>>size;
                        double temp[size];
                        cout<<"Введите подпоследовательность\n";
                        for(int i=0;i<size;i++)
                        {
                            cin>>temp[i];
                        }
                        cout<<firsts.find_subsequence(temp,size);
                    }
                        break;
                    case 6:
                    {
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }
                        firsts.map(set_nul);
                        firsts.print();
                    }
                        break;
                    case 7:
                    {
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }

                    }

                        break;
                    case 8:
                    {
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }

                    }

                        break;
                    case 9:
                    {
                        Queue<double> second;
                        Queue<double> *third;
                        if(firsts.nun())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.add_el(temps);
                            }
                        }
                        int size=0;
                        cout<<"Введите размер последовательности: ";
                        cin>>size;
                        cout<<"Введите последовательность\n";
                        for(int i=0;i<size;i++)
                        {
                            cin>>temps;
                            second.add_el(temps);
                        }
                        second.print();
                        third=firsts.concat(second);
                        third->print();
                    }

                        break;
                    default:
                        break;
                }
                cout<<"Для продолжения введите 1, иначе 0: ";
                cin>>work;



            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////
         else if(question==3)
         {

             Queue<complex<double>> firsts;
             complex<double> temps;
             int start_index,end_index;
             if(firsts.nun())
             {
                 cout<<"Заполните очередь\nВведите длину: ";
                 int len;
                 cin>>len;
                 cout<<"Введите последоваельность\n";
                 for(int i=0;i<len;i++)
                 {
                     cin>>temps;
                     firsts.add_el(temps);
                 }
             }
             while(work!=0)
             {
                 cout<<"для добавления элемента введите 1\nДля извлечения максимального элемента введите 2\nДля извлечения минимального элемента введите 3\nДля извлечения подпоследовательности введите 4\nДля поиска подпоследовательности введите 5\nMap-6\nWhere-7\nReduce-8\nConcat-9\n";
                 cin>>function;
                 switch (function)
                 {

                 case 1:
                     cout<<"Введите строку: ";
                     cin>>temps;
                     firsts.add_el(temps);
                     firsts.print();
                     break;
                 case 2:
                     cout<<firsts.get_max()<<endl;
                     break;
                 case 3:
                     cout<<firsts.get_min()<<endl;
                     break;
                 case 4:
                 {
                     if(firsts.nun())
                     {
                         cout<<"Заполните дек\nВведите длину: ";
                         int len;
                         cin>>len;
                         cout<<"Введите последоваельность\n";
                         for(int i=0;i<len;i++)
                         {
                             cin>>temps;
                             firsts.add_el(temps);
                         }
                     }
                     firsts.GetStrGreatTree();
                     cout<<"Введите начало: ";
                     cin>>start_index;
                     cout<<"Введите конец: ";
                     cin>>end_index;

                     Queue<complex<double>>* seconds=firsts.get_subsequence(start_index,end_index);
                     seconds->print();
                 }
                     break;
                 case 5:
                 {
                     if(firsts.nun())
                     {
                         cout<<"Заполните дек\nВведите длину: ";
                         int len;
                         cin>>len;
                         cout<<"Введите последоваельность\n";
                         for(int i=0;i<len;i++)
                         {
                             cin>>temps;
                             firsts.add_el(temps);
                         }
                     }
                     int size=0;
                     cout<<"Введите размер подпоследовательности: ";
                     cin>>size;
                     complex<double> temp[size];
                     cout<<"Введите подпоследовательность\n";
                     for(int i=0;i<size;i++)
                     {
                         cin>>temp[i];
                     }
                     cout<<firsts.find_subsequence(temp,size);
                 }
                     break;
                 case 6:
                 {
                     if(firsts.nun())
                     {
                         cout<<"Заполните дек\nВведите длину: ";
                         int len;
                         cin>>len;
                         cout<<"Введите последоваельность\n";
                         for(int i=0;i<len;i++)
                         {
                             cin>>temps;
                             firsts.add_el(temps);
                         }
                     }
                     firsts.map(set_nul);
                     firsts.print();
                 }
                     break;
                 case 7:
                 {
                     if(firsts.nun())
                     {
                         cout<<"Заполните дек\nВведите длину: ";
                         int len;
                         cin>>len;
                         cout<<"Введите последоваельность\n";
                         for(int i=0;i<len;i++)
                         {
                             cin>>temps;
                             firsts.add_el(temps);
                         }
                     }

                 }

                     break;
                 case 8:
                 {
                     if(firsts.nun())
                     {
                         cout<<"Заполните дек\nВведите длину: ";
                         int len;
                         cin>>len;
                         cout<<"Введите последоваельность\n";
                         for(int i=0;i<len;i++)
                         {
                             cin>>temps;
                             firsts.add_el(temps);
                         }
                     }

                 }

                     break;
                 case 9:
                 {
                     Queue<complex<double>> second;
                     Queue<complex<double>> *third;
                     if(firsts.nun())
                     {
                         cout<<"Заполните дек\nВведите длину: ";
                         int len;
                         cin>>len;
                         cout<<"Введите последоваельность\n";
                         for(int i=0;i<len;i++)
                         {
                             cin>>temps;
                             firsts.add_el(temps);
                         }
                     }
                     int size=0;
                     cout<<"Введите размер последовательности: ";
                     cin>>size;
                     cout<<"Введите последовательность\n";
                     for(int i=0;i<size;i++)
                     {
                         cin>>temps;
                         second.add_el(temps);
                     }
                     second.print();
                     third=firsts.concat(second);
                     third->print();
                 }

                     break;
                 default:
                     break;
                 }
                 cout<<"Для продолжения введите 1, иначе 0: ";
                 cin>>work;
             }
             }
        question=-1;
    }
    return 0;
}
*/


