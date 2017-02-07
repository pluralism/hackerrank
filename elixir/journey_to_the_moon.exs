defmodule JourneyToTheMoon do
  def get_vars do
    IO.gets("") |> String.trim |> String.split |> Enum.reduce([], fn(x, acc) -> acc ++ [Integer.parse(x)] end)
    |> Enum.reduce([], fn({v, _}, acc) -> acc ++ [v] end)
  end

  def eval_values(false, false, vals_branches, branches, branch_num, n1, n2) do
    {Map.put(branches, branch_num, MapSet.new |> MapSet.put(n1) |> MapSet.put(n2)),
      vals_branches |> Map.put(n1, branch_num) |> Map.put(n2, branch_num),
      branch_num + 1}
  end

  def eval_values(it1, it2, vals_branches, branches, branch_num, n1, n2) when it1 == true and it2 == true do
    if(Map.get(vals_branches, n1) == Map.get(vals_branches, n2)) do
      :ok
    end

    fst = Map.get(branches, Map.get(vals_branches, n1)) |> MapSet.to_list
    sec = Map.get(branches, Map.get(vals_branches, n2)) |> MapSet.to_list

    branches = branches |> Map.put(Map.get(vals_branches, n1), MapSet.new(Enum.uniq_by fst ++ sec, fn x -> x end))
    |> Map.delete(Map.get(vals_branches, n2))

    vals_branches = Enum.reduce(sec, vals_branches, fn(x, acc) ->
      acc |> Map.put(x, acc |> Map.get(n1))
    end)

    {branches, vals_branches, branch_num}
  end

  def eval_values(it1, it2, vals_branches, branches, branch_num, n1, n2) when it1 == true and it2 == false do
    b_tmp = MapSet.put(Map.get(branches, Map.get(vals_branches, n1)), n2)
    branches = Map.put(branches, Map.get(vals_branches, n1), b_tmp)
    vals_branches = Map.put(vals_branches, n2, Map.get(vals_branches, n1))

    {branches, vals_branches, branch_num}
  end

  def eval_values(it1, it2, vals_branches, branches, branch_num, n1, n2) when it1 == false and it2 == true do
    b_tmp = MapSet.put(Map.get(branches, Map.get(vals_branches, n2)), n1)
    branches = Map.put(branches, Map.get(vals_branches, n2), b_tmp)
    vals_branches = Map.put(vals_branches, n1, Map.get(vals_branches, n2))

    {branches, vals_branches, branch_num}
  end
end



[n, i] = JourneyToTheMoon.get_vars

map = Enum.reduce(Enum.into(0..(i - 1), []),
%{vals_branches: %{}, branches: %{}, branch_num: 1},
fn(_, acc) ->
  [n1, n2] = IO.gets("") |> String.trim |> String.split |> Enum.reduce([], fn(x, acc) -> acc ++ [Integer.parse(x)] end)
  |> Enum.reduce([], fn({v, _}, acc) -> acc ++ [v] end)

  {vals_branches, branches, branch_num} = {Map.get(acc, :vals_branches),
    Map.get(acc, :branches),
    Map.get(acc, :branch_num)}
  {it1, it2} = {Map.has_key?(vals_branches, n1),
    Map.has_key?(vals_branches, n2)}

  val =
    JourneyToTheMoon.eval_values(it1, it2, vals_branches, branches, branch_num, n1, n2)
  if val == :ok do
    %{vals_branches: vals_branches, branches: branches, branch_num: branch_num}
  else
    {branches, vals_branches, branch_num} = val
    %{vals_branches: vals_branches, branches: branches, branch_num: branch_num}
  end
end)

%{vals_branches: _, branches: branches, branch_num: _, count: _} =
  Enum.reduce(Enum.into((0..(n - 1)), []), Map.put(map, :count, 0), fn(_, acc) ->
    {vals_branches, branches, branch_num, i} = {Map.get(acc, :vals_branches),
      Map.get(acc, :branches),
      Map.get(acc, :branch_num),
      Map.get(acc, :count)}

    if(Map.get(vals_branches, i) == 0) do
      vals_branches = Map.put(vals_branches, i, branch_num)
      branches = Map.put(branches, branch_num, MapSet.new |> MapSet.put(i))

      acc |> Map.put(:vals_branches, vals_branches)
        |> Map.put(:branches, branches)
        |> Map.put(:count, i + 1)
    else
      acc
    end
  end)

branches_list = Enum.reduce(branches, [], fn({key, val}, acc) -> acc ++ [[key, val]] end)
[a, _] = Enum.reduce(branches_list, [0, 0], fn(x, [a, b]) ->
  if(List.last(branches_list) == x) do
    [a, b]
  end

  [_, l] = x
  l = MapSet.to_list(l)
  [a + (length(l) * (n - length(l) - b)), b + length(l)]
end)
IO.puts a
