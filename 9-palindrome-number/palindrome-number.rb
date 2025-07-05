def is_palindrome(x)
  return false if x < 0 || (x % 10 == 0 && x != 0)

  reversed = 0
  num = x

  while num > reversed
    reversed = reversed * 10 + num % 10
    num /= 10
  end

  num == reversed || num == reversed / 10
end
