// stack.hpp
#include <iostream>
#include <vector>
#include <typeinfo>

template <typename T, typename U>

class Stack {
    private:
        std::vector<T,U> stack_vector;
        int taille;
    public:
        Stack(int taille) :taille(taille){
            stack_vector = std::vector<T,U>(taille);
            stack_vector.shrink_to_fit();
        }

        bool isEmpty() {
            if(taille == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        
        void push(T data) {
            stack_vector.insert(stack_vector.begin() + taille, data);
            taille ++;
        }

        void push(U data) {
            stack_vector.insert(stack_vector.begin() + taille, data);
            taille ++;
        }

        int pop() {
            if(isEmpty()) {
                throw std::runtime_error("Stack is empty. Cannot pop an element.");
            }

            /*if (typeid(stack_vector[taille-1]) == T) {*/
            T popped_data = stack_vector[taille-1];
                stack_vector.erase(stack_vector.begin() + taille-1);
                taille --;

                return popped_data;
            /*} else if (typeid(stack_vector[taille-1]) == U) {
                U popped_data = stack_vector[taille-1];
                stack_vector.erase(stack_vector.begin() + taille-1);
                taille --;
            }
            std::cout << typeid(U).name() << std::endl;
            std::cout << typeid(T).name() << std::endl;*/
        }

        void print() {
            for(int i=0; i<taille; i++) {
                std::cout << stack_vector[i];
                std::cout << " ";
            }
        }

        int size() {
            return taille;
        }
};