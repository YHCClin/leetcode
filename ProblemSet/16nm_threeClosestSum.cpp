#include "Include_all.h"
using namespace std;
/*
找出nums数组中与target最接近的三个数之和
*/
struct item{
	int ab;
	int idx;
	item(int ab_,int idx_) : ab(ab_),idx(idx_) {}
	bool operator<(const item& a) const
	{
		return ab > a.ab;
	}
};

int threeSumClosest(vector<int>& nums,int target)
{
	sort(nums.begin(),nums.end());
	priority_queue<item > Heap;
	for(int i = 0;i < nums.size();++i)
	{
		item* it = new item(abs(nums[i]-target),i);
		Heap.push(*it);
	}
	int res = 0;
	for(int i = 0;i < 3;++i)
	{
		res += nums[Heap.top().idx];
		//cout << Heap.top().ab << Heap.top().idx << endl;
		Heap.pop();
	}
	return res;
}

int main()
{
	vector<int> nums = {-4,-69,34,65,56,73,733,634,2325,34523,3457535,5,3453,6345634,53456,4545,45,2,30};
	cout << threeSumClosest(nums,1000) << endl;
	
	return 0;
}