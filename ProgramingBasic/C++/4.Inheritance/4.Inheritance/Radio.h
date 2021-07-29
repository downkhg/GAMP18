#pragma once //include가 여러번된경우 1번만 사용하도록함.

class Spiker
{
	bool m_bPower;
	float m_fVolume;
public:
	Spiker()
	{
		m_bPower = false;
		m_fVolume = 0;
	}
	void SwitchOn()
	{
		m_bPower = true;
	}
	void SwitchOff()
	{
		m_bPower = false;
	}
	void VolumeUp()
	{
		m_fVolume++;
	}
	void VolumeDown()
	{
		m_fVolume--;
	}
};

class Antena
{
	float m_fHertz;
public:
	void HertzUp()
	{
		m_fHertz++;
	}
	void HertzDown()
	{
		m_fHertz--;
	}
};
//is-a: 상속을 이용하면 코드를 거이 작성하지않고 만들수있다.
class RadioIsA : public Spiker, public Antena
{

};
//has-a: 각 객체를 감싸는 함수를 만들어한다.(래퍼)
//만들때 내부의 부품을 더 좋은 부품을 사용할수있다.
//(현실에 라디오라면 직접 인터페이스를 내부에 보드에 연결하므로 여기에 해당될수도 있다.)
class RadioHasA
{
	Spiker* m_pSpiker;
	Antena* m_pAntena;
public:
	RadioHasA(Spiker* spiker, Antena* antena)
	{
		m_pSpiker = spiker;
		m_pAntena = antena;
	}
	void SwitchOn()
	{
		m_pSpiker->SwitchOn();
	}
	void SwitchOff()
	{
		m_pSpiker->SwitchOff();
	}
	void VolumeUp()
	{
		m_pSpiker->VolumeUp();
	}
	void VolumeDown()
	{
		m_pSpiker->VolumeDown();
	}
	void HertzUp()
	{
		m_pAntena->HertzUp();
	}
	void HertzDown()
	{
		m_pAntena->HertzDown();
	}
};

void RadioMain()
{
	RadioIsA cRadioIsA; //라디오를 만들수있다. 그러나 내부부품은 재활용할수없다.

	Spiker* pSpiker = new Spiker();
	Antena* pAntena = new Antena();

	//라디오를 조립할때 부품을 선택할수있고, 재활용이 가능하다.
	RadioHasA cRadio(pSpiker,pAntena);
	cRadio.SwitchOn();
	cRadio.VolumeUp();
	cRadio.HertzDown();
	cRadio.SwitchOff();

	delete pSpiker;
	delete pAntena;
}