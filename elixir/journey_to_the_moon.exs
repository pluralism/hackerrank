defmodule JourneyToTheMoon do
  defp get_vars do
    {n, _} = IO.gets |> String.trim |> Integer.parse

    {i, _} = IO.gets |> String.trim |> integer.parse
  end


  def calc_journey do
    Enum.reduce(Enum.into((0..4), []), %{vals_branches: %{}, branches: %{}, branch_num: 1}, fn(x, acc) ->
      {{n1, _}, {n2, _}} = {IO.gets("") |> String.trim |> Integer.parse,
        IO.gets("") |> String.trim |> Integer.parse}

      {:ok, vals_branches_res} = Map.fetch(acc, :vals_branches)
      {it1, it2} = {Map.has_key?(vals_branches_res, n1),
        Map.has_key?(vals_branches_res, n2)}

      acc
    end)
  end
end
