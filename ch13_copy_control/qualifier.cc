#include<iostream>
#include<string>
using namespace std;
class Animal{
	public:
		Animal& operator=(const Animal& animal) &;//&�����޶���ָ���ø�ֵ�����ֻ��������ֵ ;&&�޶���ָ����ֵ�����ֻ��������ֵ 
	private:
		string name;
		int weight;	
};
 
Animal& Animal::operator=(const Animal& animal) &{
	if(this!=&animal){
		name=animal.name;
		weight=animal.weight;
	}
	cout<<"Animal::operator=(const Animal& animal)&"<<endl;
	return *this;	
}
int main(){
	Animal bird1,bird2,bird3;
	move(bird1)=bird3;//error 
	bird2=bird3;//ok
}
