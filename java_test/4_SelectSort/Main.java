import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		
		int numsSize = s.nextInt();
		int[] nums = new int[numsSize];
		
		for (int i = 0; i < numsSize; i++)
		{
			nums[i] = s.nextInt();
		}
		
		for (int i = 0; i < numsSize - 1; i++)
		{
			int minIndex = i;
			for (int j = i; j < numsSize; j++)
			{
				if (nums[minIndex] > nums[j])
				{
					minIndex = j;
				}
			}
			swap(nums, i, minIndex);
		}
		
		for (int i = 0; i < numsSize; i++)
		{
			System.out.printf("%d ", nums[i]);
		}
	}
	
	static void swap(int[] nums, int i, int minIndex)
	{
		int temp = nums[i];
		nums[i] = nums[minIndex];
		nums[minIndex] = temp;
	}
}