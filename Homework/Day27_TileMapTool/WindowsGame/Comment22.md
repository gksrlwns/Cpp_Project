## 공격하면 공격모션대로 flipbook 전환
 - Idle,
 - Move
 - Attack
 

```
 해야할 내용 (수도코드)

 1. 마우스 좌클릭을하면 State가 Attack으로 변경


 2. Attack일시, 
	- Update_Attack으로 변경
	- flipbook 변경 (SetState)

 3. Update_Attack에서 현재 진행중인 프레임을 따져서
    - 공격 이벤트가 설정된 프레임이 지났으면 공격하도록 설정
```


 1. 마우스 좌클릭을하면 State가 Attack으로 변경
  - Attack이라는 상태값을 만들어줘야합니다.

  ### 아래코드의 문제점이 있음.
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
	else
	{
		_creature->SetState(Day24CreatureState::Idle);
	}

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		_creature->SetState(Day24CreatureState::Attack);

		// TODO :
		// Update_Attack에서 현재 진행중인 프레임을 따져서
		//	- 공격 이벤트가 설정된 프레임이 지났으면 공격하도록 설정


		Vector2 dir = Input->GetMousePosVector2() - _creature->GetSreenPos();
		dir = dir.Normalize();
		_creature->Shoot(dir);
	}
```
 - 키를 누르면 상태를 변화하고 (Move, Attack으로)
 - 키를 누르지않으면 Idle로 변화하고 있는 로직입니다.

 - 변경되는거까지는 큰 상관이 없는데.
	- Idle 상태에서 좌클릭을 누르면
	- Attack이 됩니다.
	- 1프레임 (0.016초) 이후에 다시 Idle이 됩니다.

### 그렇기 떄문에 Attack이 끝날때까지 계속 Attack을 유지하기 위한 수정방안

```
 1. Scene에서 입력을 받을때
  - 어떤방향으로 움직여야하는지 최종 inputDir을 받을겁니다.
   [움직이지 않으면, inputDir = (0, 0)]
  - Update_Move
	(inputDir이 있으면 그 방향으로 움직임 수정)
  - Update_Idle
    (inputDir이 있으면 그 방향으로 움직임 수정)
  - Update_Attack
    inputDir이 있어도 무시.

 Input에 대한 정보는 모두 GameObject에 넘기지만
 실질적인 판단은 상태에따라서 GameObject가 알아서 처리하도록
```

응용으로 평타캔슬 이런것도 가능하겠죠
(평타치다가 중간에 움직이는거)

