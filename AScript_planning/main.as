

int add(int x, int y) {
	return x+y;
}

void add(int x, int y, int* res) {
	*res = x+y;
}

int main() {
	int x;
	float y = 1.09;
	char ch;
	int arr[10] = {0};
	int* p;
	p = &x;
	char str[] = "hi my name is";
	
	x=1;
	if(x == 1){
		x=3;
	}
	else {
		x=4;
	}
	
	return 0;
}