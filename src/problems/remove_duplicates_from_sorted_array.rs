pub struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut unique_index = 0;

        for current_index in 0..nums.len() {
            if nums[current_index] != nums[unique_index] {
                nums.swap(current_index, unique_index + 1);
                unique_index += 1;
            }
        }

        (unique_index + 1) as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 1, 2], 2)]
    #[case(vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4], 5)]
    #[case(vec![1, 1, 2, 3, 3, 4], 4)]
    fn test_remove_duplicates(#[case] mut nums: Vec<i32>, #[case] expected: i32) {
        let result = Solution::remove_duplicates(&mut nums);
        let k = usize::try_from(result).unwrap();
        let k_expected = usize::try_from(expected).unwrap();
        assert_eq!(result, expected);
        assert_eq!(&nums[..k], &nums[..k_expected]);
    }
}
