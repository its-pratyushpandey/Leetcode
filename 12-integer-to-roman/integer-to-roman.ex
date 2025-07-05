defmodule Solution do
  @roman_map [
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
  ]

  @spec int_to_roman(integer) :: String.t()
  def int_to_roman(num) when num >= 1 and num <= 3999 do
    convert(num, @roman_map, "")
  end

  defp convert(0, _map, result), do: result

  defp convert(num, [{value, symbol} | rest], result) do
    if num >= value do
      convert(num - value, [{value, symbol} | rest], result <> symbol)
    else
      convert(num, rest, result)
    end
  end
end
