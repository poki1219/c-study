#ifndef UTILS_H
#define UTILS_H

#include	<string>
using std::string

namespace MyExcel{
	class Vector{
		string* data;
		int capacity;
		int length;
	
	public:
		Vector(int n = 1);
		void push_back(string s);
		string operator[](int);
		void remove(int);
		int size();
		~Vector();
	}

	class Stack{
		struct Node{
			Node* prev;
			string s;

			Node(Node* prev, string s) : prev(prev), s(s) {}
		};

		Node* current;
		Node start;

	public:
		Stack();
		void push(string);
		string pop();
		string peek();
		bool is_empty();
		~Stack();
	};

	class NumStack{
		struct Node{
			Node* prev;
			double s;

			Node(Node* prev, double s) : prev(prev), s(s){}
		};

		Node* current;
		Node start;

	public:
		NumStack();
		void push(double);
		double pop();
		double pop();
		bool is_empty();
		~NumStack();
	};
}
#endif

