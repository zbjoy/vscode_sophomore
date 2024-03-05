import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		
		double num = s.nextDouble();
		double step = s.nextDouble();
		
		for (; num <= 1.0; num += step)
		{
			getNum(num);
		}
	}
	
	public static void getNum(double num)
	{
		double sum = 0;
		int i = 0;
		while (true)
		{
			double temp = mPow(num, i) / factorial_sum(i);
			if ((temp > 0 && temp <= 0.00001) || (temp <= 0 && temp >= -0.00001))
			{
				break;
			}
			
			sum += temp;
			
			i++;
		}
		
		System.out.println(String.format("x=%.2f时,e(x)的值为:%.6f", num, sum));
	}
	
	public static double mPow(double x, int n)
	{
		if (n == 0)
		{
			return 1;
		}
		
		double temp = x;
		
		for (int i = 1; i < n; i++)
		{
			temp *= x;
		}
		
		return temp;
	}
	
	public static double factorial_sum(int n)
	{
		if (n == 0)
		{
			return 1;
		}
		
		double sum = 1;
		for (int i = 1; i <= n; i++)
		{
			sum *= i;
		}
		
		return sum;
	}
}