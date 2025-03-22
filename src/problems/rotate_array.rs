pub struct Solution1;

impl Solution1 {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let mut rotated_nums = nums.clone();
        let k = usize::try_from(k).unwrap();

        for (i, &num) in nums.iter().enumerate() {
            rotated_nums[(i + k) % nums.len()] = num;
        }

        nums.copy_from_slice(&rotated_nums);
    }
}

pub struct Solution2;

impl Solution2 {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let k = usize::try_from(k).unwrap();
        let n = k % nums.len();
        nums.reverse();
        nums[..n].reverse();
        nums[n..].reverse();
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 4, 5, 6, 7], 3, vec![5, 6, 7, 1, 2, 3, 4])]
    #[case(vec![-1, -100, 3, 99], 2, vec![3, 99, -1, -100])]
    #[case(vec![1, 2, 3], 0, vec![1, 2, 3])]
    #[case(vec![1, 2, 3], 4, vec![3, 1, 2])]
    #[case(vec![1], 3, vec![1])]
    fn test_rotate(#[case] nums: Vec<i32>, #[case] k: i32, #[case] expected: Vec<i32>) {
        {
            let mut nums = nums.clone();
            Solution1::rotate(&mut nums, k);
            assert_eq!(nums, expected);
        }
        {
            let mut nums = nums.clone();
            Solution2::rotate(&mut nums, k);
            assert_eq!(nums, expected);
        }
    }
}
