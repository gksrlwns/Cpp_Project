## 공격하면 공격모션대로 flipbook 전환
- Idle
- Move
- Attack

```
해야할 내용(수도코드)
1. 마우스 좌클릭을 하면 State가 Attack으로 변경

2. Attack일 시, 
	- Update_Attack으로 변경
	- flipbook 변경 (SetState)
3. Update_Attack에서 현재 진행중인 프레임을 따져서
공격 이벤트가 설정된 프레임이 지났으면 공격하도록 설정
```

```cpp
if (Input->GetKey(KeyCode::W))
	{
		_creature->SetDir(Day24CreatureDir::Up);
		_creature->SetState(Day24CreatureState::Move);
	}
	else if (Input->GetKey(KeyCode::S))
	{
		_creature->SetDir(Day24CreatureDir::Down);
		_creature->SetState(Day24CreatureState::Move);
	}
	else if (Input->GetKey(KeyCode::A))
	{
		_creature->SetDir(Day24CreatureDir::Left);
		_creature->SetState(Day24CreatureState::Move);
	}
	else if (Input->GetKey(KeyCode::D))
	{
		_creature->SetDir(Day24CreatureDir::Right);
		_creature->SetState(Day24CreatureState::Move);
	}
	else if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		_creature->SetState(Day24CreatureState::Attack);
		//TODO:
		// Attack 프레임을 따져서 공격이 나오도록
		//

		//화면상에서의 좌표는 GetPos로 하면 안됨.
		Vector2 dir = Input->GetMousePosVector2() - _creature->GetScreenPos();
		dir = dir.Normalize();
		_creature->Shoot(dir);
	}
```
- 키를 누르면 상태를 변환하고
- 키룰 누르지 않으면 Idle로 변화하고 잇는 로직
-  변경되는 거 가지는 상관이없는데
	- idle 상태에서 좌클릭을 누르면 Attack이 됨
	- 1프레임 이후에 다시 Idle로 변경됨
## 그렇기 때문에 Attack 이 끝날 때 까지 계속 attack 을 유지하기 위한 수정방법
```
1. Scene에서 입력을 받을 때
- 어떤 방향으로 움직여야하는지 최종 Dir을 받을 것임
(움직이지 않으면, inputDir = (0,0))
-Update_Move_
inputDir이 있으면 그 방향으로 움직임 수정
-Update_Idel
inputDir이 있으면 그 방향으로 움직임 수정
-Update_Attack
inputDir이 있어도 무시

Input에 대한 정보는 모두 GameObject에 넘기지만 
실질적인 판단은 상태에 따라서 GameObject가 알아서 처리하도록
```