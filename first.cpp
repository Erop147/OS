#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
void add(char *name, vector<int> &res)
{
	FILE *in = fopen(name, "r");
	if (in == NULL)
	{
		fprintf(stderr, "file %s dosn't exist\n", name);
		return;
	}
	int num;
    while (!feof(in))
    {
    	if (fscanf (in, "%d", &num) <= 0)
    	{
    		fprintf(stderr, "file %s contains non digit\n", name);
    		break;
    	}
    	try
    	{
    		res.push_back(num);
    	}
    	catch (exception e)
    	{
    		fprintf(stderr, "something wrong with vectors");
    		break;
    	}
    }
	fclose(in);
}
int main(int argv, char* args[])
{
	vector<int> numbers;
	for (int i = 1; i < argv; ++i)                       
	{
		add(args[i], numbers);
	}
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < (int)numbers.size(); ++i)
	{
		printf ("%d ", numbers[i]);
	}
	return 0; 
}