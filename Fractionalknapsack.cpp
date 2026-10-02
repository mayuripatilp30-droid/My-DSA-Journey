#include <iostream>
#include <algorithm>
using namespace std;

struct Item{
	int weight;
	int profit;
	double ratio;
};

bool compare(Item a, Item b){
	return a.ratio > b.ratio;
}

int main(){
	int n;
	double capacity;
	
	cout<<"Enter number of items: ";
	cin>>n;
	
	Item items[n];
	
	cout<<" Enter weight and profit of each item: \n";
	
	for(int i=0; i<n; i++){
		cout<<"Item"<<i+1<<"weight: ";
		cin>> items[i].weight;
		
		cout<<"Item"<<i+1<<"profit:";
		cin>> items[i].profit;
		
		items[i].ratio = (double)items[i].profit/items[i].weight; 
	}
	
	cout<<"Enter capacity of knapsack: ";
	cin>>capacity;
	
	sort(items, items+n, compare);
	
	double totalProfit = 0;
	
	for(int i=0; i<n; i++){
		if (capacity>= items[i].weight){
			capacity-=items[i].weight;
			totalProfit+=items[i].profit;
		}
		else{
			totalProfit+=items[i].profit*(capacity / items[i].weight);
			capacity = 0;
			break;
		}
	}
	
	cout<<"\nMaximum Profit = "<<totalProfit<<endl;
	
	return 0;
}
