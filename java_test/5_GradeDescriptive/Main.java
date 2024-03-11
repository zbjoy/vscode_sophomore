import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		
		int nums = s.nextInt();
		int[] score = new int[nums];
		
		for (int i = 0; i < nums; i++)
		{
			score[i] = s.nextInt();
		}
		
		int max = 0;
		int sum = 0;
		float avg = 0.0f;
		int fail = 0;
		int pass = 0;
		int middle = 0;
		int good = 0;
		int excellent = 0;
		
		for (int i = 0; i < nums; i++)
		{
			if (max < score[i])
			{
				max = score[i];
			}
			
			sum += score[i];
			
			if (score[i] < 60)
			{
				fail++;
			}
			else if (score[i] < 70 && score[i] >= 60)
			{
				pass++;
			}
			else if (score[i] < 80 && score[i] >= 70)
			{
				middle++;
			}
			else if (score[i] < 90 && score[i] >= 80)
			{
				good++;
			}
			else
			{
				excellent++;
			}
		}
		
		
		avg = (float)sum / (float)nums;
		
		System.out.printf("max:%.1f\n", (float)max);
		System.out.printf("avg:%.2f\n", avg);
		System.out.printf("fail:%d\n", fail);
		System.out.printf("pass:%d\n", pass);
		System.out.printf("middle:%d\n", middle);
		System.out.printf("good:%d\n", good);
		System.out.printf("excellent:%d\n", excellent);
	}
}