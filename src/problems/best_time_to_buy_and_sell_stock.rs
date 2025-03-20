use std::cmp;

pub struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut min_price = &prices[0];
        let mut max_profit = 0;

        for price in &prices {
            max_profit = cmp::max(max_profit, price - min_price);
            min_price = cmp::min(min_price, price);
        }

        max_profit
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![7, 1, 5, 3, 6, 4], 5)]
    #[case(vec![7, 6, 4, 3, 1], 0)]
    fn test_max_profit(#[case] prices: Vec<i32>, #[case] expected: i32) {
        let result = Solution::max_profit(prices);
        assert_eq!(result, expected);
    }
}
