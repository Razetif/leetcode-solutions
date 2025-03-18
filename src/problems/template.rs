pub struct Solution;

impl Solution {
    pub fn add(x: i32, y: i32) -> i32 {
        x + y
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(1, 2, 3)]
    #[case(1, -2, -1)]
    #[case(0, 0, 0)]
    fn test_add(#[case] x: i32, #[case] y: i32, #[case] expected: i32) {
        let result = Solution::add(x, y);
        assert_eq!(result, expected);
    }
}
