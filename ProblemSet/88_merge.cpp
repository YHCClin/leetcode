#include "Include_all.h"
using namespace std;

void merge(vector<int>& nums1,int m,vector<int>& nums2,int n)
{
	//假定nums1足够大
	int i;
	if (m==0)
	{
		for(int a = m+n-1,b = n-1;a >= 0;a--,b--)
		{
			nums1[a] = nums2[b];
		}
		return;
	}
	else
	{
		i = m-1;
	}
	int j = n-1,k = m+n-1;
	while(j>=0 && i>=0)
	{
		if(nums1[i]>=nums2[j])
		{
			nums1[k] = nums1[i];
			i--;
			k--;
		}
		else
		{
			nums1[k] = nums2[j];
			j--;
			k--;
		}

	}
	if(i < 0)
	{
		while(k>=0 && j>=0)
		{
			nums1[k] = nums2[j];
			k--;
			j--;
		}
	}
	if(j < 0)
	{
		while(k>=0 && j>=0)
		{
			nums1[k] = nums1[i];
			k--;
			i--;
		}
	}
}

int main()
{
	std::vector<int> nums1{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	std::vector<int> nums2{-50,-50,-48,-47,-44,-44,-37,-35,-35,-32,-32,-31,-29,-29,-28,-26,-24,-23,-23,-21,-20,-19,-17,-15,-14,-12,-12,-11,-10,-9,-8,-5,-2,-2,1,1,3,4,4,7,7,7,9,10,11,12,14,16,17,18,21,21,24,31,33,34,35,36,41,41,46,48,48};
	merge(nums1,0,nums2,63);
	for(auto i : nums1)
	{
		cout << i << endl;
	}
	return 0;
}

/*
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
0
[-50,-50,-48,-47,-44,-44,-37,-35,-35,-32,-32,-31,-29,-29,-28,-26,-24,-23,-23,-21,-20,-19,-17,-15,-14,-12,-12,-11,-10,-9,-8,-5,-2,-2,1,1,3,4,4,7,7,7,9,10,11,12,14,16,17,18,21,21,24,31,33,34,35,36,41,41,46,48,48]
63
*/