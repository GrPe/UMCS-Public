class CTablica
{
	float *arr;
	int size;
public:
	CTablica(int s)
	{
		arr = new float[s];
		size = s;
	}
	~CTablica()
	{
		delete[] arr;
	}
	CTablica(CTablica& obiekt)
	{
		size = obiekt.size;
		arr = new float[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = obiekt.arr[i];
		}
	}
};

int main()
{
	CTablica tablica(5);
	CTablica kopia = tablica;

	return 0;
}
