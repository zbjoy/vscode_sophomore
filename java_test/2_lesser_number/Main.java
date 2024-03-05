import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		int num = s.nextInt();
		int cols = 0;
		
		int currentNum = 0;
		int nextNum = 0;
		
		boolean flag;
		
		while (true)
		{
			currentNum = num % 10;
			if (num / 10 <= 0)
			{
				flag = true;
				break;
			}
			
			num /= 10;
			nextNum = num % 10;
			
			if (nextNum < currentNum)
			{
				flag = false;
				break;
			}
			

		}
		
		System.out.println(flag);
	}
}