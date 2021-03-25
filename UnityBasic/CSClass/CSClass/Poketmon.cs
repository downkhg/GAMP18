using System;
using System.Collections.Generic;
using System.Text;
/*
 * 포켓몬 유사게임 모작하기
1.트레이너는 처음 포켓몬이 하나 주어진다.
2.트레이너가 가고 싶은 지역을 선택하고,
3.해당지역에 포켓몬을 만나고 쓰러뜨리면, 해당포켓몬을 획득할수있다.
4.획득한 포켓몬은 싸우기 전에 결정이 가능하다.
*/
namespace CSClass
{
    class Pokemon
    {
        public string Name;

    }
    class Trainner
    {
        List<Pokemon> pokemons;

        public void Catch(Pokemon target)
        {
            pokemons.Add(target);
        }

        public Pokemon Throw(string name)
        {
            return pokemons.Find(x => x.Name == name);
        }
    }
}
