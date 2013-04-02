//============================================================================
// Name        : different Concepts2.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share,copy and distribute
// Description : This file has clarified some concept of c++ :template,iterators,std::algorithm funcs,
//				 vector operations,macros
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,N) for(i = 0;i < N;i++)
#define FORG(i,start,end) for(i = start; i != end;i++)
#define FORGR(i,start,end) for(i = start; i != end; i--)
//traverse macro for any STL container
#define traverse(C,it)\
	for(typeof(C.begin()) it = C.begin() ; it != C.end();it++)
#define all(v) v.begin(),v.end()

using namespace std;

//reverse method of an array
//It uses only four distinct operations on pointers 'first' and 'last':
//compare pointers (first < last),
//get value by pointer (*first, *last),
//increment pointer, and
//decrement pointer
void reverseArray(int *A,int N){
	int *first,*last;
	first = A;
	last = A + N - 1;
	while(first < last){
		swap(*first,*last);
		first++;
		last--;
	}
}

//STL iterator
//The following operations are defined for iterators:
//get value of an iterator, int x = *it;
//increment and decrement iterators it1++, it2--;
//compare iterators by '!=' and by '<'
//add an immediate to iterator it += 20; <=> shift 20 elements forward
//get the distance between iterators, int n = it2-it1;

//reverseArray function for any type
template<typename T>
void reverseArrayT(T *first,T *last){
	//normal iterator doesn't provide < or > operator. So we have to use == and != instead
	if(first != last){
		while(true){
			std::swap(*first,*last);
			first++;
			if(first == last)
				break;
			last--;
			if(first == last)
				break;
		}
	}
}


template<typename T>
void reverseArraySTLCcompliant(T* begin, T* end){
	using namespace std;
	end--; // because end is the iterator that points to the next element of the last element of the containers
	if(begin != end){
		while(1){
			swap(*begin,*end);
			begin++;
			if(begin == end){
				break;
			}
			end--;
			if(begin == end){
				break;
			}
		}
	}
}

//const iterator for const vector reference
int func(const vector<int>& v){
	int r = 0;
	//vector<int>::iterator it;
	traverse(v,it){
		r += (*it) * (*it);
	}
	return r;
}


template<typename T>
void showContainer(const T& v){
	typeof(v.begin()) it = v.begin();
	traverse(v,it){
		cout << *it << " ";
	}
	cout << endl;
}




int m3(){
	int a[5] = {5,4,3,2,1};
	reverseArrayT(a,a + 5 - 1);

	int i;
//	FOR(i,5){
//		cout << a[i] << " ";
//	}

	 int data[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	 int data2[5] = {5,7,9,10,13};

	 vector<int> v(data,data + sizeof(data)/sizeof(data[0]));//similar to previous def

	 FOR(i,10){
		 cout << v.at(i) << " " ;
	 }
	 reverse(v.begin(),v.end());
	 cout << endl;
	 FOR(i,10){
	 		 cout << v.at(i) << " " ;
	 	}

	 cout << endl;
	 vector<int>::iterator it;
	 traverse(v,it){
		 cout << *it << " " ;
	 }
	 cout << endl;
	 reverse(v.rbegin(),v.rend());

	 traverse(v,it){
		 cout << *it << " " ;
	 }

	 //printing reverse order begin and end element
	 cout << endl << *v.rbegin() << endl << *(v.rend() - 1) << endl;

	 vector<int> v2(v.rbegin() + v.size()/2 , v.rend());
	 traverse(v2,it){
	 	 		 cout << *it << " " ;
	 	 }

	 //printing the index of the element 15 in v
	 int index = (find(v.begin(),v.end(),15)) - v.begin();
	 cout << endl;
	 cout << index << endl;

	 int max = *max_element(v.begin(),v.end());
	 int min = *min_element(v.begin(),v.end());

	 cout << max << endl << min << endl;

	 int b=3,c=5;

//typeof chooses the type of the rhs for x
	 typeof(b+c) x = (b+c);
	 cout << x<<endl;
	 cout << "r =" ;

	 //calling func
	 cout << func(v) << endl;


//insert elements from vectors
	 cout <<endl<< "INSERT" << endl;
	 v.insert(v.begin(),30);
	 showContainer(v);
	 v.insert(v.begin() + 5,10);
	 showContainer(v);

	 vector<int> v3(data2,data2 + sizeof(data2)/sizeof(data2[0]));



     //inserting a range of data
	 cout <<"inserting a range of data" << endl;
	 v.insert(v.begin(),v.begin(),v.end());

	 //inserting v3[0]~v3[4] in v[5]~v[9] and shifting v[5]~v[v.size()] to v[10]~v[10+v.size()
	cout << "inserting v3[0]~v3[4] in v[5]~v[9] and shifting v[5]~v[v.size()] to v[10]~v[10+v.size()" << endl;
	 v.insert(v.begin() + 5,all(v3));

	 showContainer(v3);
	 showContainer(v);

	 v.insert(v.end(),1000);
	 showContainer(v);



//erase elements from vector v2
	 cout << "erase elements from vector v2"<< endl;
	 cout << endl << "erase" << endl;
	 showContainer(v2);
	 cout<< "erasing the fourth element and then shifting"<< endl;
	 v2.erase(v2.begin() + 3); //erasing the fourth element and then shifting
	 showContainer(v2);
	 //erasing a range of elements of v
	 cout << "erasing from v[3] to v[10]" << endl;
	 showContainer(v);
	 v.erase(v.begin() + 3,v.begin() + 11) ;//erasing from v[3] to v[10]
	 showContainer(v);



	return 0;
}
