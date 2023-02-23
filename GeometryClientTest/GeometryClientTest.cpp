#include "pch.h"
#include "CppUnitTest.h"
#include "../Point3D.cpp"
#include "../Vector3D.cpp"
#include "../DataPointParser.cpp"
#include "../DataPoint.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

float relativeTolerance = 0.00001; // 0.001% -> used to compare points for equality

namespace GeometryClientTest
{




	TEST_CLASS(Geometry3DTest)
	{
	public:
		
		TEST_METHOD(Point3DEqualsTest)
		{
			Point3D point1 = Point3D(1.653, 1.982, 1.333);
			Point3D point2 = Point3D(1.653, 1.982, 1.333);
			Assert::IsTrue(point1.samePointAs(point2, relativeTolerance));

			Point3D point3 = Point3D(1.65300001, 1.982, 1.333);
			Point3D point4 = Point3D(1.653, 1.982, 1.333);
			Assert::IsTrue(point3.samePointAs(point4, relativeTolerance));
		}

		TEST_METHOD(Point3DNotEqualsTest)
		{
			Point3D point1 = Point3D(1.0001, 1.0, 1.0);
			Point3D point2 = Point3D(1.0, 1.0, 1.0);
			Assert::IsFalse(point1.samePointAs(point2, relativeTolerance));
		}

		TEST_METHOD(Vector3DEqualsTest)
		{
			Vector3D vector1 = Vector3D(1.653, 1.982, 1.333);
			Vector3D vector2 = Vector3D(1.653, 1.982, 1.333);
			Assert::IsTrue(vector1.sameVectorAs(vector2, relativeTolerance));

			Vector3D vector3 = Vector3D(1.65300001, 1.982, 1.333);
			Vector3D vector4 = Vector3D(1.653, 1.982, 1.333);
			Assert::IsTrue(vector3.sameVectorAs(vector4, relativeTolerance));
		}

		TEST_METHOD(Vector3DNotEqualsTest)
		{
			Vector3D vector1 = Vector3D(1.0001, 1.0, 1.0);
			Vector3D vector2 = Vector3D(1.0, 1.0, 1.0);
			Assert::IsFalse(vector1.sameVectorAs(vector2, relativeTolerance));
		}

		TEST_METHOD(Point3DOffsetTest)
		{
			Point3D originalPoint1 = Point3D(1.0, 2.0, 3.0);
			Vector3D offsetVector1 = Vector3D(1.0, 0.0, 0.0);
			Point3D* newPoint1 = originalPoint1.offsetByVector(offsetVector1);
			Point3D verifyPoint1 = Point3D(2.0, 2.0, 3.0);
			Assert::IsTrue(newPoint1->samePointAs(verifyPoint1, relativeTolerance));

			Point3D originalPoint2 = Point3D(1.0, 1.0, 1.0);
			Vector3D offsetVector2 = Vector3D(-1.0, -2.0, -3.0);
			Point3D* newPoint2 = originalPoint2.offsetByVector(offsetVector2);
			Point3D verifyPoint2 = Point3D(0.0, -1.0, -2.0);
			Assert::IsTrue(newPoint2->samePointAs(verifyPoint2, relativeTolerance));

			Point3D originalPoint3 = Point3D(1.0, -2.0, 3.0);
			Vector3D offsetVector3 = Vector3D(-1.0, 2.0, 3.0);
			Point3D* newPoint3 = originalPoint3.offsetByVector(offsetVector3);
			Point3D verifyPoint3 = Point3D(0.0, 0.0, 6.0);
			Assert::IsTrue(newPoint3->samePointAs(verifyPoint3, relativeTolerance));

			Point3D originalPoint4 = Point3D(-1.0, -2.0, 3.0);
			Vector3D offsetVector4 = Vector3D(1.0, -2.0, -3.0);
			Point3D* newPoint4 = originalPoint4.offsetByVector(offsetVector4);
			Point3D verifyPoint4 = Point3D(0.0, -4.0, 0.0);
			Assert::IsTrue(newPoint4->samePointAs(verifyPoint4, relativeTolerance));
		}

		TEST_METHOD(Vector3DUnitvectorTest)
		{
			Vector3D originalVector1 = Vector3D(3.0, 0.0, 0.0);
			Vector3D verifyVector1 = Vector3D(1.0, 0.0, 0.0);
			Vector3D unitVector1 = originalVector1.getUnitVector();
			Assert::IsTrue(unitVector1.sameVectorAs(verifyVector1, relativeTolerance));

			Vector3D originalVector2 = Vector3D(-3.0, 0.0, 0.0);
			Vector3D verifyVector2 = Vector3D(-1.0, 0.0, 0.0);
			Vector3D unitVector2 = originalVector2.getUnitVector();
			Assert::IsTrue(unitVector2.sameVectorAs(verifyVector2, relativeTolerance));

			Vector3D originalVector3 = Vector3D(0.0, 3.0, 3.0);
			Vector3D verifyVector3 = Vector3D(0.0, 0.70710678, 0.70710678);
			Vector3D unitVector3 = originalVector3.getUnitVector();
			Assert::IsTrue(unitVector3.sameVectorAs(verifyVector3, relativeTolerance));

			Vector3D originalVector4 = Vector3D(3.0, 3.0, -3.0);
			Vector3D verifyVector4 = Vector3D(0.57735027, 0.57735027, -0.57735027);
			Vector3D unitVector4 = originalVector4.getUnitVector();
			Assert::IsTrue(unitVector4.sameVectorAs(verifyVector4, relativeTolerance));
		}

		TEST_METHOD(Vector3DMultiplyTest)
		{
			Vector3D originalVector1 = Vector3D(1.0, 1.0, 1.0);
			Vector3D verifyVector1 = Vector3D(2.0, 2.0, 2.0);
			double factor1 = 2.0;
			Vector3D scaledVector1 = originalVector1 * factor1;
			Assert::IsTrue(scaledVector1.sameVectorAs(verifyVector1, relativeTolerance));

			Vector3D originalVector2 = Vector3D(-1.0, -1.0, -1.0);
			Vector3D verifyVector2 = Vector3D(-2.0, -2.0, -2.0);
			double factor2 = 2.0;
			Vector3D scaledVector2 = originalVector2 * factor2;
			Assert::IsTrue(scaledVector2.sameVectorAs(verifyVector2, relativeTolerance));

			Vector3D originalVector3 = Vector3D(-1.0, -1.0, 1.0);
			Vector3D verifyVector3 = Vector3D(2.0, 2.0, -2.0);
			double factor3 = -2.0;
			Vector3D scaledVector3 = originalVector3 * factor3;
			Assert::IsTrue(scaledVector3.sameVectorAs(verifyVector3, relativeTolerance));

			Vector3D originalVector4 = Vector3D(1.0, 1.0, 1.0);
			Vector3D verifyVector4 = Vector3D(0.0, 0.0, 0.0);
			double factor4 = 0.0;
			Vector3D scaledVector4 = originalVector4 * factor4;
			Assert::IsTrue(scaledVector4.sameVectorAs(verifyVector4, relativeTolerance));
		}

	};

	TEST_CLASS(PointMeasurementParserTest)
	{
	public:

		std::string inputString =
			"E0000 # PtMeas(X(-711.2140549),Y(863.4),Z(400.6150898),IJK(-0.3746066,0.0,0.9271839),R(1.1679))";
		DataPointParser parser = DataPointParser(inputString);

		TEST_METHOD(findXTest)
		{
			Assert::AreEqual(parser.findXvalue(), -711.2140549);
		}

		TEST_METHOD(findYTest)
		{
			Assert::AreEqual(parser.findYvalue(), 863.4);
		}

		TEST_METHOD(findZTest)
		{
			Assert::AreEqual(parser.findZvalue(), 400.6150898);
		}

		TEST_METHOD(findNormalXTest)
		{
			Assert::AreEqual(parser.findNormalXvalue(), -0.3746066);
		}

		TEST_METHOD(findNormalYTest)
		{
			Assert::AreEqual(parser.findNormalYvalue(), 0.0);
		}

		TEST_METHOD(findNormalZTest)
		{
			Assert::AreEqual(parser.findNormalZvalue(), 0.9271839);
		}

		TEST_METHOD(findRTest)
		{
			Assert::AreEqual(parser.findRvalue(), 1.1679);
		}

	};

	TEST_CLASS(PointMeasurementTest)
	{
	public:

		std::string inputString =
			"E0000 # PtMeas (X(100), Y(100), Z(100), IJK(5.1,6.2,7.3), R(5))";
		DataPoint dataPoint = DataPoint(inputString);

		TEST_METHOD(collisionPointCalcTest)
		{
			Vector3D normalVector = Vector3D(5.1, 6.2, 7.3);
			Point3D measurementPoint = Point3D(100, 100, 100);
			double sphereRadius = 5.0;

			// Tested in Geometry3DTest->Vector3DUnitvectorTest
			Vector3D unitVector = normalVector.getUnitVector();

			// Reversing unitvector, tested in Geometry3DTest->Vector3DMultiplyTest
			Vector3D unitVectorReversed = unitVector * -1;

			// Multiplying by sphere radius
			Vector3D offsetVector = unitVectorReversed * sphereRadius;

			// Offsetting point, tested in Vector3DMultiplyTest->Point3DOffsetTest			
			Point3D verifyPoint = *measurementPoint.offsetByVector(offsetVector);


			Point3D* point = dataPoint.getCollisionPoint();
			Assert::IsTrue(verifyPoint.samePointAs(*point, relativeTolerance));
		}

	};


}
