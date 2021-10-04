# Arduino_Separate-collection-Robot
아두이노 기반 이미지 분류 쓰레기 분리수거 로봇팔

## 1. 프로젝트 기간
- 2020.09.10 ~ 2020.12.10 약 3개월

## 2. 프로젝트 외관
![image](https://user-images.githubusercontent.com/78673090/133480075-8c4f592c-6a1a-4fdb-8550-2fcdda6ff20f.png)

## 3. 프로젝트 구성
#### 3.1 흐름도
![image](https://user-images.githubusercontent.com/78673090/133483125-3f40aa69-06c5-48ab-98bc-8a479619b510.png)

Object_Detection_Teachable_Machine.py 설명
- 아두이노 시리얼 포트 번호를 입력하여 파이썬과 연동하게 설정
- labels.txt 파일을 읽고 keras_model.h5의 Class 순서에 맞게끔 함
- 실시간 영상 처리 진행
- 실시간 영상에서 1번 Class가 예측값 0.8이 넘을 경우 배경으로 인식하여 'a' 문자를 시리얼 통신으로 아두이노에 전송 (배경)
- 실시간 영상에서 2번 Class가 예측값 0.8이 넘을 경우 배경으로 인식하여 'b' 문자를 시리얼 통신으로 아두이노에 전송 (유리)
- 실시간 영상에서 3번 Class가 예측값 0.8이 넘을 경우 배경으로 인식하여 'c' 문자를 시리얼 통신으로 아두이노에 전송 (캔)
- 실시간 영상에서 4번 Class가 예측값 0.8이 넘을 경우 배경으로 인식하여 'd' 문자를 시리얼 통신으로 아두이노에 전송 (플라스틱)

robot_arm.ino 설명
- 각 관절 부위의 서보모터 확인 후 변수 지정한 뒤 관절마다의 각도 확인
- 유리, 플라스틱, 초기 함수를 만들어 서보 모터를 어떻게 움직일 것인지 설정 (캔 같은 경우 트레일러를 이용하여 옮기려고 했으나 트레일러와 로봇팔의 동시 연동이 안 되어 캔은 트레일러가 동작한다는 가정하에 진행) 
- 파이썬에서 출력한 각 문자별로 각 함수 실행

#### 3.2 하드웨어 구성
- 웹 카메라
- Arduino Mega
- 로봇 팔
- 서보 모터
- LED

## 4. 소프트웨어 개발 환경 설정
#### 4.1 개발 환경
- Python (3.7버전이 가장 호환이 잘 되는 것을 확인)
- Arduino Sketch
- Visual Studio Code (웹 페이지를 생성하기 위해)
- Atom (아두이노와 파이썬을 연결하기 위해, vscode를 사용할 줄 알면 굳이 설치 안 해도 됨)

#### 4.2 파이썬 라이브러리 설치
- pip install tensorflow==1.15
- pip install pillow
- pip install numpy
- pip install opencv-python
- pip install opencv-contrib-python
- pip install pyserial

#### 4.3 아두이노 시리얼 통신 설정
- 아두이노 시리얼 포트 / 통신 속도 확인 후
- Object_Detection_Teachable_Machine.py파일에서 port, baudrate 변수에 입력

## 5. Teachable Machine
#### 5.1 이미지 프로젝트 (표준 이미지 모델)

#### 5.2 분류하고자 하는 물체 촬영 및 이미지 삽입 (여기서 사용한 분류는 총 4가지 : 배경, 캔, 플라스틱, 유리)
- Class 1 : background
- Class 2 : glass
- Class 3 : can
- Class 4 : plastic

#### 5.3 학습 (고급 설정 값은 사용자 마음, 여기서는 기본값으로 진행)
- 에포크 : 50
- 배치 크기 : 16
- 학습률 : 0.001

#### 5.4 모델 내보내기
- Tensorflow.js에서 모델에서 사용할 코드 스니펫 부분 복사 (웹 사이트 생성할때 사용)
- Tensorflow.js에서 모델 다운로드
- Tensorflow에서 Keras 유형 선택 후 모델 다운로드 (keras_model.h5 파일이 생성 되는지 확인)

## 6. 웹 사이트 생성 (google 검색하면 다양한 정보를 얻을 수 있음)
1. Tensorflow.js에서 모델 다운받은 압축파일 해제 후 폴더를 생성하여 폴더 안에 파일 넣음
2. 폴더에서 확장자 html 파일 생성 후 vscode로 열기
3. vscode에서 !+tab 키로 html 코드 생성 후 body 부분에 위에서 복사한 코드 입력하고 저장
4. netlify 사이트 접속하여 저장한 vscode 파일 배포하여 웹 사이트 생성
- 실제 만든 웹 사이트 주소 : https://test-final-taehyun-1213.netlify.app/
![image](https://user-images.githubusercontent.com/78673090/133476747-2de5ef5a-308d-4c64-92c4-4d4f13bc68c4.png)

## 7. 파이썬과 아두이노 연동
#### 7.1 Label 파일 수정
- 업로드 한 labels.txt에서 본인이 위 2.2에서 설정한 Class 순서로 0번 부터 작성 후 저장
#### 7.2 Atom 프로그램 실행 후 Object_Detection_Teachable_Machine.py 파일과 robot_arm.ino 넣고 실행
