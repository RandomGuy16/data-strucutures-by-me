#include <vector>
#if !defined(MY_UNIONFIND)
#define MY_UNIONFIND

class my_unionfind
{
private:
	std::pmr::vector<int> parents;
	std::pmr::vector<int> ranks;
public:
	explicit my_unionfind(int n);
	~my_unionfind() = default;

	int find(int x);

	bool unify(int x, int y);

	void print_data() const;

};


#endif // MY_UNIONFIND
