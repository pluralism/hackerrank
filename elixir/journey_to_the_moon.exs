defmodule JourneyToTheMoon do
  def get_vars do
    {n, _} = IO.gets("") |> String.trim |> Integer.parse
    {i, _} = IO.gets("") |> String.trim |> Integer.parse
    {n, i}
  end

  def eval_values(false, false, vals_branches, branches, branch_num, n1, n2) do
    vals_branches = Map.put(vals_branches, n1, branch_num)
    vals_branches = Map.put(vals_branches, n2, branch_num)
    branches = Map.put(branches, branch_num, MapSet.new |> MapSet.put(n1)
      |> MapSet.put(n2))

    {branches, vals_branches, branch_num + 1}
  end

  def eval_values(it1, it2, vals_branches, branches, branch_num, n1, n2) when it1 == true and it2 == true do
    if(Map.get(vals_branches, n1) == Map.get(vals_branches, n2)) do
      :ok
    end

    fst = Map.get(branches, Map.get(vals_branches, n1))
    sec = Map.get(branches, Map.get(vals_branches, n2))

    branches = Map.put(branches, Map.get(vals_branches, n1), Enum.uniq(fst ++ sec))
    branches = Map.delete(branches, Map.get(vals_branches, n2))

    vals_branches = Enum.reduce(sec, vals_branches, fn(x, acc) ->
      acc |> Map.put(x, acc |> Map.get(n1))
    end)

    {branches, vals_branches, branch_num}
  end

  def eval_values(it1, it2, vals_branches, branches, branch_num, n1, n2) when it1 == true and it2 == false do
    branches = MapSet.put(branches, Map.get(vals_branches, n1), n2)
    vals_branches = Map.put(vals_branches, n2, Map.get(vals_branches, n1))

    {branches, vals_branches, branch_num}
  end

  def eval_values(it1, it2, vals_branches, branches, branch_num, n1, n2) when it1 == false and it2 == true do
    branches = MapSet.put(branches, Map.get(vals_branches, n2), n1)
    vals_branches = Map.put(vals_branches, n1, Map.get(vals_branches, n2))

    {branches, vals_branches, branch_num}
  end


  def calc_journey do
    {n, i} = get_vars

    map = Enum.reduce(Enum.into(0..(i - 1), []), %{vals_branches: %{}, branches: %{}, branch_num: 1},
    fn(_, acc) ->
      {{n1, _}, {n2, _}} = {IO.gets("") |> String.trim |> Integer.parse,
        IO.gets("") |> String.trim |> Integer.parse}

      {vals_branches, branches, branch_num} = {Map.get(acc, :vals_branches),
        Map.get(acc, :branches),
        Map.get(acc, :branch_num)}
      {it1, it2} = {Map.has_key?(vals_branches, n1),
        Map.has_key?(vals_branches, n2)}

      {branches, vals_branches, branch_num} =
        eval_values(it1, it2, vals_branches, branches, branch_num, n1, n2)
      %{vals_branches: vals_branches, branches: branches, branch_num: branch_num}
    end)

    IO.inspect map

    %{vals_branches: vals_branches, branches: branches, branch_num: branch_num, count: count} =
      Enum.reduce(Enum.into((0..(n - 1)), []), Map.put(map, :count, 0), fn(x, acc) ->
        vals_branches = Map.get(acc, :vals_branches)
        branches = Map.get(acc, :branches)
        branch_num = Map.get(acc, :branch_num)
        i = Map.get(acc, :count)

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
  end
end
