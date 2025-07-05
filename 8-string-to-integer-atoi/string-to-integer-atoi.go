package main

import (
	"math"
	"unicode"
)

func myAtoi(s string) int {
	i := 0
	n := len(s)

	for i < n && s[i] == ' ' {
		i++
	}

	if i == n {
		return 0
	}

	sign := 1
	if s[i] == '-' {
		sign = -1
		i++
	} else if s[i] == '+' {
		i++
	}

	result := 0
	for i < n && unicode.IsDigit(rune(s[i])) {
		digit := int(s[i] - '0')
		if result > (math.MaxInt32-digit)/10 {
			if sign == 1 {
				return math.MaxInt32
			}
			return math.MinInt32
		}
		result = result*10 + digit
		i++
	}

	return sign * result
}
