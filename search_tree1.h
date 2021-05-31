#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

//#include "sequence.h"
//#include "array.h"
using namespace std;

template<typename T>
class Search_tree
{
private:

    struct node
    {
        T data = 0;
        node *pLeft = nullptr;
        node *pRight = nullptr;
    };

    node* root;
    int length;

     void print_t(node* ptr)
     {
         node*temp=ptr;
         if(temp==nullptr)
             return;
         print_t(temp->pLeft);
         cout<<temp->data<< " ";
         print_t(temp->pRight);

     }

     void klp(node* ptr, D_Array<T>* res)
     {
         if(ptr==nullptr)
             return;
         res->prepend(ptr->data);
         klp(ptr->pLeft,res);
         klp(ptr->pRight,res);
     }

     void lkp(node* ptr, D_Array<T>* res)
     {
         if(ptr==nullptr)
             return;
         lkp(ptr->pLeft,res);
         res->prepend(ptr->data);
         lkp(ptr->pRight,res);
     }


public:

     //КОНСТРУКТОРЫ

    Search_tree()
    {
        this->root=nullptr;
        length=0;
    }

    Search_tree(T* item, int len)
    {
        bool fl=true;
        this->root= new node;
        this->root->data=*(item+0);
        this->length=len;

        for(int i=1; i<len;i++)
        {
            node* temp=this->root;
            fl=true;
            while (fl)
            {
                if(temp->data>*(item+i))
                {
                    if(temp->pLeft==nullptr)
                    {
                        temp->pLeft=new node;
                        temp=temp->pLeft;
                        temp->data=*(item+i);
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pLeft;
                    }
                }
                else
                {
                    if(temp->pRight==nullptr)
                    {
                        temp->pRight=new node;
                        temp=temp->pRight;
                        temp->data=*(item+i);
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pRight;
                    }
                }
            }
        }
    }

    Search_tree(D_Array<T>* arr)
    {
        bool fl=true;
        int len=1;
        this->root= new node;
        this->root->data=arr->p_front();
        T data;

        while(!arr->nun())
        {
            len++;
            data=arr->p_front();
            node* temp=this->root;
            fl=true;
            while (fl)
            {
                if(temp->data>data)
                {
                    if(temp->pLeft==nullptr)
                    {
                        temp->pLeft=new node;
                        temp=temp->pLeft;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pLeft;
                    }
                }
                else
                {
                    if(temp->pRight==nullptr)
                    {
                        temp->pRight=new node;
                        temp=temp->pRight;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pRight;
                    }
                }
            }
        }
        this->length=len;
    }



    Search_tree(Search_tree<T>& other)
    {
        D_Array<T>* arr = other.klp_t();
        bool fl=true;
        int len=1;
        this->root= new node;
        this->root->data=arr->p_front();
        T data;

        while(!arr->nun())
        {
            len++;
            data=arr->p_front();
            node* temp=this->root;
            fl=true;
            while (fl)
            {
                if(temp->data>data)
                {
                    if(temp->pLeft==nullptr)
                    {
                        temp->pLeft=new node;
                        temp=temp->pLeft;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pLeft;
                    }
                }
                else
                {
                    if(temp->pRight==nullptr)
                    {
                        temp->pRight=new node;
                        temp=temp->pRight;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pRight;
                    }
                }
            }
        }
        this->length=len;

    }

    int get_length()
    {
        return this->length;
    }

    D_Array<T>* klp_t()
    {
        node* temp=this->root;
        D_Array<T>*res=new D_Array<T>();
        this->klp(temp,res);
        res->Array_Output();
        return res;
    }

    D_Array<T>* lkp_t()
    {
        node* temp=this->root;
        D_Array<T>*res=new D_Array<T>();
        this->lkp(temp,res);
        res->Array_Output();
        return res;

    }



// 5 баллов
//----------------------------------------------------
    //ВСТАВКА

    void add_el(T data)
    {
        this->length+=1;
        if(this->root==nullptr)
        {
            this->root=new node;
            this->root->data=data;
            this->root->pLeft=nullptr;
            this->root->pRight=nullptr;
        }
        else
        {
            bool fl=true;
            node* temp=this->root;
            while (fl)
            {
                if(temp->data>data)
                {
                    if(temp->pLeft==nullptr)
                    {
                        temp->pLeft=new node;
                        temp=temp->pLeft;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pLeft;
                    }
                }
                else
                {
                    if(temp->pRight==nullptr)
                    {
                        temp->pRight=new node;
                        temp=temp->pRight;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pRight;
                    }
                }
            }
        }

    }

    //ПОИСК

    bool find_el(T data)
    {
        node* temp=this->root;
        if(temp==nullptr)
        {
            cout<<"Дерево пусто";
            return false;
        }
        while (true)
        {
            if(temp->data>data)
            {
                if(temp->pLeft==nullptr)
                    return false;
                temp=temp->pLeft;
            }
            else if(temp->data<data)
            {
                if(temp->pRight==nullptr)
                    return false;
                temp=temp->pRight;
            }
            else if(temp->data==data)
                return true;
        }
    }

    node* Find_Min(node* ptr)
    {
        if(ptr==nullptr)
            return ptr;
        else if(ptr->pLeft==nullptr)
            return ptr;
        else
            return Find_Min(ptr->pLeft);
    }
    node* Find_Max(node* ptr)
     {
         if(ptr==nullptr)
             return ptr;
         else if(ptr->pRight==nullptr)
             return ptr;
         else
             return Find_Max(ptr->pRight);
     }

    //УДАЛЕНИЕ

     node* Delete(node* ptr, T dat)
     {
         node* temp;
         if(temp==nullptr)
             return nullptr;
         if(ptr->data>dat)
             Delete(ptr->pLeft, dat);
         else if(ptr->data<dat)
             Delete(ptr->pRight, dat);
         else
         {
             if(ptr->pLeft==nullptr && ptr->pRight==nullptr)
             {
                 delete ptr;
                 ptr=nullptr;
             }
             else if(ptr->pLeft!=nullptr && ptr->pRight!=nullptr)
             {
                 temp=Find_Min(ptr->pRight);
                 ptr->data=temp->data;
                 ptr->pRight=Delete(ptr->pRight, dat);
             }
             else
             {
                 temp=ptr;
                 if(ptr->pRight==nullptr)
                     ptr=ptr->pLeft;
                 else if(ptr->pLeft==nullptr)
                     ptr=ptr=ptr->pRight;
                 delete temp;
             }
         }
         return ptr;
     }

//-------------------------------------------


    //СОХРАНЕНИЕ В СТРОКУ ПО ОБХОДУ, ЗАДАВАЕМОМУ ПОЛЬЗОВАТЕЛЕМ - 3 балла

    void In_Str(node* ptr, D_Array<T>* res, char a, char b, char c)
    {
        if(ptr==nullptr)
            return;
        switch (a)
        {
            default:
                break;
            case 'L':
               In_Str(ptr->pLeft, res, a, b, c);
            case 'K':
                res->prepend(ptr->data);
            case 'R':
                In_Str(ptr->pRight, res, a, b, c);
        }
        switch (b)
        {
            default:
                break;
            case 'L':
                In_Str(ptr->pLeft, res, a, b, c);
            case 'K':
                res->prepend(ptr->data);
            case 'R':
                In_Str(ptr->pRight, res, a, b, c);
        }
        switch (c)
        {
            default:
                break;
            case 'L':
                In_Str(ptr->pLeft, res, a, b, c);
            case 'K':
                res->prepend(ptr->data);
            case 'R':
                In_Str(ptr->pRight, res, a, b, c);
        }
    }

    //ИЗВЛЕЧЕНИЕ ПОДДЕРЕВА - 2 балла

    Search_tree* get_subtree(T data)
    {
        node* temp=this->root;
        if(temp==nullptr)
        {
            cout<<"Дерево пусто";   //TODO заменить на обработку через класс
            return nullptr;
        }
        bool fl=true;
        while (fl)
        {
            if(temp->data>data)
            {
                if(temp->pLeft==nullptr)
                {
                    cout<<"такого поддерева нет\n";
                    return nullptr;
                }
                temp=temp->pLeft;
            }
            else if(temp->data<data)
            {
                if(temp->pRight==nullptr)
                {
                    cout<<"такого поддерева нет\n";
                    return nullptr;
                }
                temp=temp->pRight;
            }
            else if(temp->data==data)
                fl=false;
        }
        D_Array<T>* res= new D_Array<T>();
        this->klp(temp,res);
        Search_tree<T> *ret=new Search_tree<T>(res);
        return ret;
    }

    //ПОИСК НА ВХОЖДЕНИЕ ПОДДЕРЕВА - 3 балла

    bool find_subtree(Search_tree<T>& other)
    {
        D_Array<T> *arr1=new D_Array<T>();
        D_Array<T> *arr2=new D_Array<T>();
        arr1=this->klp_t();
        arr2=other.klp_t();
        int fl=arr1->find_subsequence(*arr2);
        return fl!=0;
    }

    //СУММА ДЕРЕВЬЕВ

    Search_tree* concat(Search_tree<T>& other)   //TODO можно по другому что с одинаковыми элементами
    {
        D_Array<T> *arr1=new D_Array<T>();
        D_Array<T> *arr2=new D_Array<T>();
        arr1=this->klp_t();
        arr2=other.klp_t();
        D_Array<T> *arr=arr1->concat(arr2);
        Search_tree<T> *res=new Search_tree<T>(arr);
        return res;
    }

    //MAP, WHERE, REDUCE - 3 балла

    Search_tree* map(T(*func)(T))
    {
        D_Array<T> *arr=this->klp_t();
        arr->map(func);
        Search_tree<T>* res=new Search_tree<T>(arr);
        return res;
    }

    Search_tree* map(T(*func)(void))
    {
        D_Array<T> *arr=this->klp_t();
        arr->map(func);
        Search_tree<T>* res=new Search_tree<T>(arr);
        return res;
    }

    Search_tree* where(bool(*func)(T))
    {
        D_Array<T> *arr=this->klp_t();
        arr->where(func);
        Search_tree<T>* res=new Search_tree<T>(arr);
        return res;
    }

    T reduce(T(*func)(T))
    {
        D_Array<T>* d1=this->klp_t();
        int res = d1->reduce(func);
        return res;
    }

};
/*
bool operator >(complex<double>& c1, complex<double>& c2)
{
    double p11= pow(c1.imag(),2);
    double p12= pow(c1.real(),2);
    double p21= pow(c2.imag(),2);
    double p22= pow(c2.real(),2);
    double mc1=sqrt((p11+p12));
    double mc2=sqrt((p21+p22));
    bool res=mc1>mc2;
    return res;
}
*/
#endif // SEARCH_TREE_H
