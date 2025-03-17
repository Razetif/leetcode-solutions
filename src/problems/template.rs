pub struct Solution;

impl Solution {
    pub fn add(x: i32, y: i32) -> i32 {
        x + y
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn positive_numbers() {
        let result = Solution::add(1, 2);
        assert_eq!(result, 3);
    }

    #[test]
    fn negative_numbers() {
        let result = Solution::add(1, -2);
        assert_eq!(result, -1);
    }

    #[test]
    fn zeros() {
        let result = Solution::add(0, 0);
        assert_eq!(result, 0);
    }
}
