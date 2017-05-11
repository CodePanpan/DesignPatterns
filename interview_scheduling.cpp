#include <iostream>
#include <algorithm>
#include <vector>

class Data
{
    public:
    int sums;
    int indices;
    bool operator()(const Data &a, const Data &b)
    {
        if (a.sums < b.sums) return false;
        else return true;
    }
};

int main()
{
	int N;
	std::cin>>N;
	//Data structures
	int Info[N][3];
	std::vector<Data> Sum;
	//Input
	for (int i = 0; i < N; ++i)
	{
		std::cin>>Info[i][0];
		std::cin>>Info[i][1];
		std::cin>>Info[i][2];
		Data d;
		d.sums = Info[i][0];
		d.sums += Info[i][1];
		d.sums += Info[i][2];
		d.indices = i;
		Sum.push_back(d);
	}
	//sorting
	std::sort(Sum.begin(), Sum.end(), Data());
	//modify sorted order
	for (int i = 0; i < N; ++i)
	{
		//fix at i
		int ind = i;
		while (ind > 0 && (Sum[ind].sums == Sum[ind - 1].sums))
		{
			if (Info[Sum[ind].indices][0] < Info[Sum[ind-1].indices][0])
				std::swap<Data>(Sum[ind], Sum[ind-1]);
			ind--;
		}
	}
	//find the max
	int mx = 0;
	int sm = 0;
	for (int i = 0; i < N; ++i)
	{
		int ind = Sum[i].indices;
		int val = Info[ind][0] + Info[ind][1] + Info[ind][2] + sm;
		sm += Info[ind][0];
		if (mx < val) mx = val;
	}

	std::cout<<mx<<std::endl;

	return 0;
}
