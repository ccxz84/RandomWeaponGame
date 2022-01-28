# RandomWeaponGame
## Unreal Engine 빌드

### EpicGames 계정 Github 연동

https://www.unrealengine.com/ko/ue4-on-github?sessionInvalidated=true

EpicGames 계정을 Github와 연동해야 함.

---
### Install & configure git

Windows용 Git 설치

https://git-scm.com/download/win

Install & configure git
```
$ git config -–global user.name “name”
$ git config –-global user.email name@test.com
$ git config –-global core.editor vim
$ git config –-global merge.tool vimdiff
$ git config –-global core.pager “less -r”
```

---
### Unreal Engine Clone

https://github.com/EpicGames/UnrealEngine

![1](https://user-images.githubusercontent.com/22430531/150782681-abc6c1d1-03a3-4fa1-b22d-8cb707e848da.png)

```
git clone git@github.com:EpicGames/UnrealEngine.git --dept 1
```

### Visual Studio 2022 설치

https://my.visualstudio.com/Downloads?q=visual%20studio%202022

![2](https://user-images.githubusercontent.com/22430531/150782723-cee9c5f0-c0a9-4bbd-9292-fc5d8f41d509.png)

* 위의 옵션으로 Visual Studio 2022 설치

### .NET Framework 4.6.2

https://dotnet.microsoft.com/en-us/download/dotnet-framework/thank-you/net462-developer-pack-offline-installer

설치를 진행한다.

### Unreal Engine Build

* Setup.bat 실행

* GenerateProjectFiles.bat 실행

* UE4.sln 더블 클릭하여 Visual Studio 2022 실행

![3](https://user-images.githubusercontent.com/22430531/150782644-823aa036-f5a5-4aef-9421-6fd8cdec3fab.PNG)

* UE4를 시작 프로젝트로 지정

![4](https://user-images.githubusercontent.com/22430531/150782805-fd288d0b-3dc7-41dd-927c-9c5f029d2593.PNG)

* 빌드 항목을 지정

![6](https://user-images.githubusercontent.com/22430531/150782888-3228776c-df7f-4143-bf90-cb9861224012.PNG)

* 로컬 디버거 실행

![5](https://user-images.githubusercontent.com/22430531/150782910-cb1da8b4-23ce-4c97-bd64-29cda80a152a.PNG)

* 솔루션 탐색기에서 위의 항목을 찾아 우클릭 후, 빌드 진행

  Engine\Binaries\Win64 디렉터리에 UE4Editor.exe 생겼으면 성공

## Project Setting

### Project Clone

```
git clone git@github.com:RandomWeaponGame/RandomWeaponGame.git
```

### Visual Studio Code 설치

https://code.visualstudio.com/

### Visual Studio 2022 Build Tools 설치

https://aka.ms/vs/17/release/vs_buildtools.exe

![7](https://user-images.githubusercontent.com/22430531/150783899-edc96848-48d8-4de3-bae4-3931a616a7a8.png)

* 위의 옵션으로 Visual Studio 2022 Build Tools 설치 ( 설치 시, 경로를 Program File이 아닌 띄어쓰기가 없이 영어로만 되어있는 경로로 바꿀 것.)

### Unreal Engine Setting

* UnrealEngine\Engine\Binaries\Win64\UE4Editor.exe 실행

![8](https://user-images.githubusercontent.com/22430531/150784092-27f02e70-4ffe-4750-b6eb-d06ed9dc9487.png)

* 게임 클릭

![9](https://user-images.githubusercontent.com/22430531/150784153-9f986947-88e9-42c2-a59b-37e9c6ad5dda.png)

* 기본 프로젝트 생성

![10](https://user-images.githubusercontent.com/22430531/150784216-8947bc4c-c4a2-4e80-b34e-9e52bf50168d.png)

* 아무렇게나 생성 ( 사용하지 않을 프로젝트임 )

![11](https://user-images.githubusercontent.com/22430531/150784399-b733d896-9208-4197-8fb8-f60998904696.png)

* 편집 - 에디터 개인설정

![12](https://user-images.githubusercontent.com/22430531/150784461-858183a9-2538-4361-a0f7-5fa6371054ac.png)

* 소스코드 - 소스 코드 에디터 Visual Studio Code로 변경

### Visual Studio Code Setting

* Visual Studio Code 실행

![14](https://user-images.githubusercontent.com/22430531/150785440-a39a229b-8114-4aa7-95f5-0b77a0b754e2.png)

![15](https://user-images.githubusercontent.com/22430531/150785447-12af8224-3a86-4136-9883-62038aa733a3.PNG)

* 위와 같이 Plugin 설치

### Project Build

* Project Clone 받은 경로로 이동

* RandomWeaponGame.uproject 우클릭 후, Switch Unreal Engine Version 클릭

![13](https://user-images.githubusercontent.com/22430531/150784816-b4bbdea5-bb32-4ce3-a58e-38fea3bde310.png)

* 본인이 Build한 Unreal Engine 경로로 지정.

* RandomWeaponGame.uproject 우클릭 후, Generate Visual Studio project files 클릭

* Visual Studio Code 켠 후, Project Import.

![16](https://user-images.githubusercontent.com/22430531/150785888-e7d1db66-4bb1-4813-8bb2-997f7f23f8c0.png)

* 실행 및 디버그 - RandomWeaponEditor (Development) 설정 후, 빌드

